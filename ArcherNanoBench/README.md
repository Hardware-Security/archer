
# nanoBench

*nanoBench* is a Linux-based tool for running small microbenchmarks on recent Intel and AMD x86 CPUs. The microbenchmarks are evaluated using [hardware performance counters](https://en.wikipedia.org/wiki/Hardware_performance_counter). The reading of the performance counters is implemented in a way that incurs only minimal overhead.

There are two variants of the tool: A user-space implementation and a kernel module. The kernel module makes it possible to benchmark privileged instructions, and it can allow for more accurate measurement results as it disables interrupts and preemptions during measurements. The disadvantage of the kernel module compared to the user-space variant is that it is quite risky to allow arbitrary code to be executed in kernel space. Therefore, the kernel module should not be used on a production system.

*nanoBench* is used for running the microbenchmarks for obtaining the latency, throughput, and port usage data that is available on [uops.info](http:www.uops.info).

## Integrator
A file added for integrating everything into the json, named "Integrator.py"

## Installation

### User-space Version

    sudo apt install msr-tools
    git clone https://github.com/andreas-abel/nanoBench.git
    cd nanoBench
    make user

*nanoBench might not work if Secure Boot is enabled. [Click here](https://askubuntu.com/a/762255/925982) for instructions on how to disable Secure Boot.*

### Kernel Module
*Note: The following is not necessary if you would just like to use the user-space version.*

    git clone https://github.com/andreas-abel/nanoBench.git
    cd nanoBench
    make kernel

To load the kernel module, run:

    sudo insmod kernel/nb.ko # this is necessary after every reboot

## Usage Examples

The recommended way for using *nanoBench* is with the wrapper scripts `nanoBench.sh` (for the user-space variant) and `kernel-nanoBench.sh` (for the kernel module). The following examples work with both of these scripts.

For obtaining repeatable results, it can help to disable hyper-threading. This can be done with the `disable-HT.sh` script.

### Example 1: The ADD Instruction

The following command will benchmark the assembler code sequence "ADD RAX, RBX; ADD RBX, RAX" on a Skylake-based system.

    sudo ./nanoBench.sh -asm "ADD RAX, RBX; add RBX, RAX" -config configs/cfg_Skylake_common.txt

It will produce an output similar to the following.
    
    Instructions retired: 2.00
    Core cycles: 2.00
    Reference cycles: 1.85
    UOPS_ISSUED.ANY: 2.00
    UOPS_EXECUTED.THREAD: 2.00
    UOPS_DISPATCHED_PORT.PORT_0: 0.49
    UOPS_DISPATCHED_PORT.PORT_1: 0.50
    UOPS_DISPATCHED_PORT.PORT_2: 0.00
    UOPS_DISPATCHED_PORT.PORT_3: 0.00
    UOPS_DISPATCHED_PORT.PORT_4: 0.00
    UOPS_DISPATCHED_PORT.PORT_5: 0.50
    UOPS_DISPATCHED_PORT.PORT_6: 0.51
    UOPS_DISPATCHED_PORT.PORT_7: 0.00
    ...

The tool will *unroll* the assembler code multiple times, i.e., it will create multiple copies of it. The results are averages per copy of the assembler code for multiple runs of the entire generated code sequence.

The config file contains the required information for configuring the programmable performance counters with the desired events. We provide example configuration files for recent Intel and AMD microarchitectures in the `config` folder.

The assembler code sequence may use and modify any general-purpose or vector registers (unless the `-loop` or `-no_mem` options are used), including the stack pointer. There is no need to restore the registers to their original values at the end.

R14, RDI, RSI, RSP, and RBP are initialized with addresses in the middle of dedicated memory areas (of 1 MB each), that can be freely modified by the assembler code.

All other registers have initially undefined values. They can, however, be initialized as shown in the following example.

### Example 2: Load Latency

    sudo ./nanoBench.sh -asm_init "mov RAX, R14; sub RAX, 8; mov [RAX], RAX" -asm "mov RAX, [RAX]" -config configs/cfg_Skylake_common.txt

The `asm-init` code is executed once in the beginning. It first sets RAX to R14-8 (thus, RAX now contains a valid memory address), and then sets the memory at address RAX to its own address. Then, the `asm` code is executed repeatedly. This code loads the value at the address in RAX into RAX. Thus, the execution time of this instruction corresponds to the L1 data cache latency.

We will get an output similar to the following.

    Instructions retired: 1.00
    Core cycles: 4.00
    Reference cycles: 3.52
    UOPS_ISSUED.ANY: 1.00
    UOPS_EXECUTED.THREAD: 1.00
    UOPS_DISPATCHED_PORT.PORT_0: 0.00
    UOPS_DISPATCHED_PORT.PORT_1: 0.00
    UOPS_DISPATCHED_PORT.PORT_2: 0.50
    UOPS_DISPATCHED_PORT.PORT_3: 0.50
    ...
    MEM_LOAD_RETIRED.L1_HIT: 1.00
    MEM_LOAD_RETIRED.L1_MISS: 0.00
    ...

## Generated Code

We will now take a look behind the scenes at the code that *nanoBench* generates for evaluating a microbenchmark.

    int run(code, code_init, local_unroll_count):
        int measurements[n_measurements]
        
        for i=-warm_up_count to n_measurements
            save_regs
            code_init
            m1 = read_perf_ctrs // stores results in memory, does not modify registers
            for j=0 to loop_count // this line is omitted if loop_count=0
                code // (copy #1)
                code // (copy #2)
                 ⋮
                code // (copy #local_unroll_count)
            m2 = read_perf_ctrs
            restore_regs
            if i >= 0: // ignore warm-up runs
                measurements[i] = m2 - m1
                
        return agg(measurements) // apply selected aggregate function

`run(...)` is executed twice: The first time with `local_unroll_count = unroll_count`, and the second time with `local_unroll_count = 2 * unroll_count`. If the `-basic_mode` options is used, the first execution is with no instructions between `m1 = read_perf_ctrs` and `m2 = read_perf_ctrs`, and the second with `local_unroll_count = unroll_count`. 


The result that is finally reported by *nanoBench* is the difference between these two executions divided by `max(loop_count * unroll_count, unroll_count)`. 

Before the first execution of `run(...)`, the performance counters are configured according to the event specifications in the `-config` file. If this file contains more events than there are programmable performance counters available, `run(...)` is executed multiple times with different performance counter configurations.

    

## Command-line Options

Both `nanoBench.sh` and `kernel-nanoBench.sh` support the following command-line parameters. All parameters are optional. Parameter names may be abbreviated if the abbreviation is unique (e.g., `-l` may be used instead of `-loop_count`).

| Option                       | Description |
|------------------------------|-------------|
| `-asm <code>`                | Assembler code sequence (in Intel syntax) containing the code to be benchmarked. |
| `-asm_init <code>`           | Assembler code sequence (in Intel syntax) that is executed once before executing the benchmark code. |
| `-code <filename>`           | A binary file containing the code to be benchmarked as raw x86 machine code.  *This option cannot be used together with `-asm`.* |
| `-code_init <filename>`      | A binary file containing code to be executed once before executing the benchmark code. *This option cannot be used together with `-asm_init`.* |
| `-config <file>`             | File with performance counter event specifications. Details are described [below](#performance-counter-config-files).  |
| `-n_measurements <n>`        | Number of times the measurements are repeated. `[Default: n=10]` |
| `-unroll_count <n>`          | Number of copies of the benchmark code inside the inner loop. `[Default: n=1000]` |
| `-loop_count <n>`            | Number of iterations of the inner loop. If n>0, the code to be benchmarked **must not modify R15**, as this register contains the loop counter. If n=0, the instructions for the loop are omitted; the loop body is then executed once. `[Default: n=0]` |
| `-warm_up_count <n>`         | Number of runs of the generated benchmark code sequence (in each invocation of `run(...)`) before the first measurement result gets recorded . This can, for example, be useful for excluding outliers due to cold caches.   `[Default: n=5]` |
| `-initial_warm_up_count <n>` | Number of runs of the benchmark code sequence before the first invocation of `run(...)`. This can be useful for benchmarking instructions that require a warm-up period before they can execute at full speed, like [AVX2 instructions on some microarchitectures](https://www.agner.org/optimize/blog/read.php?i=415).  `[Default: n=0]` |
| `-avg`                       | Selects the arithmetic mean (excluding the top and bottom 20% of the values) as the aggregate function. `[This is the default]` |
| `-median`                    | Selects the median as the aggregate function. |
| `-min`                       | Selects the minimum as the aggregate function. |
| `-basic_mode`                | The effect of this option is described in the [Generated Code](#generated-code) section. |
| `-no_mem`                    | If this option is enabled, the code for `read_perf_ctrs` does not make any memory accesses and stores all performance counter values in registers. This can, for example, be useful for benchmarks that require that the state of the data caches does not change after the execution of `code_init`. *If this option is used, the code to be benchmarked must not modify registers* ***R8-R11 (Intel)*** *and* ***R8-R13 (AMD).*** *Furthermore, `read_perf_ctrs` will modify* ***RAX, RCX, and RDX***. |
| `-cpu <n>`                   | Pins the measurement thread to CPU n. `[Default: Pin the thread to the CPU it is currently running on.]` |
| `-verbose`                   | Outputs the results of all performance counter readings. In the user-space version, the results are printed to stdout. The output of the kernel module can be accessed using `dmesg`. |

The following parameters are only supported by `nanoBench.sh`.

| Option     | Description |
|------------|-------------|
| `-usr <n>` | If n=1, performance events are counted when the processor is operating at a privilege level greater than 0. `[Default: n=1]` |
| `-os <n>`  | If n=1, performance events are counted when the processor is operating at privilege level 0.  `[Default: n=0]` |
| `-debug`   | Enables the debug mode (see [below](#debug-mode)). |


## Performance Counter Config Files

We provide provide performance counter configuration files for most recent Intel and AMD CPUs in the `configs` folder. These files can be adapted/reduced to the events you are interested in.

The format of the entries in the configuration files is

    EvtSel.UMASK(.CMSK=...)(.AnyT)(.EDG)(.INV)(.CTR=...)(.MSR_3F6H=...)(.MSR_PF=...)(.MSR_RSP0=...)(.MSR_RSP1=...) Name

You can find details on the meanings of the different parts of the entries in chapters 18 and 19 of [Intel's System Programming Guide](https://software.intel.com/sites/default/files/managed/a4/60/325384-sdm-vol-3abcd.pdf).

## Debug Mode

If the debug mode is enabled, the [generated code](#generated-code) contains a breakpoint right before the line `m2 = read_perf_ctrs`, and *nanoBench* is run using *gdb*. This makes it possible to analyze the effect of the code to be benchmarked on registers and on the memory. The command `info all-registers` can, for example, be used to display the current values of all registers.

## Supported Platforms

*nanoBench* should work with all Intel processors supporting architectural performance monitoring version ≥ 3, as well as with AMD Family 17h processors.

The code was developed and tested using Ubuntu 18.04.
