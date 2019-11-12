#ifndef TESTCASES_H
#define TESTCASES_H

#include <test_types.h>


extern void clcopy();

extern void clload();

extern void clstore();

extern void copy();

extern void copy_avx();

extern void copy_avx512();

extern void copy_mem();

extern void copy_mem_avx();

extern void copy_mem_avx512();

extern void copy_mem_sse();

extern void copy_sse();

extern void daxpy();

extern void daxpy_avx();

extern void daxpy_avx512();

extern void daxpy_avx512_fma();

extern void daxpy_avx_fma();

extern void daxpy_mem_avx();

extern void daxpy_mem_avx512();

extern void daxpy_mem_avx512_fma();

extern void daxpy_mem_avx_fma();

extern void daxpy_mem_sse();

extern void daxpy_mem_sse_fma();

extern void daxpy_sp();

extern void daxpy_sp_avx();

extern void daxpy_sp_avx512();

extern void daxpy_sp_avx512_fma();

extern void daxpy_sp_avx_fma();

extern void daxpy_sp_mem_avx();

extern void daxpy_sp_mem_avx512();

extern void daxpy_sp_mem_avx512_fma();

extern void daxpy_sp_mem_avx_fma();

extern void daxpy_sp_mem_sse();

extern void daxpy_sp_mem_sse_fma();

extern void daxpy_sp_sse();

extern void daxpy_sp_sse_fma();

extern void daxpy_sse();

extern void daxpy_sse_fma();

extern void ddot();

extern void ddot_avx();

extern void ddot_avx512();

extern void ddot_sp();

extern void ddot_sp_avx();

extern void ddot_sp_avx512();

extern void ddot_sp_sse();

extern void ddot_sse();

extern void divide();

extern void load();

extern void load_avx();

extern void load_avx512();

extern void load_mem();

extern void load_sse();

extern void peakflops();

extern void peakflops_avx();

extern void peakflops_sse();

extern void store();

extern void store_avx();

extern void store_avx512();

extern void store_mem();

extern void store_mem_avx();

extern void store_mem_avx512();

extern void store_mem_sse();

extern void store_sse();

extern void stream();

extern void stream_avx();

extern void stream_avx512();

extern void stream_avx512_fma();

extern void stream_avx_fma();

extern void stream_mem();

extern void stream_mem_avx();

extern void stream_mem_avx_fma();

extern void stream_mem_sse();

extern void stream_mem_sse_fma();

extern void stream_sp();

extern void stream_sp_avx();

extern void stream_sp_avx512();

extern void stream_sp_avx512_fma();

extern void stream_sp_avx_fma();

extern void stream_sp_mem_avx();

extern void stream_sp_mem_avx512();

extern void stream_sp_mem_avx512_fma();

extern void stream_sp_mem_avx_fma();

extern void stream_sp_mem_sse();

extern void stream_sp_mem_sse_fma();

extern void stream_sp_sse();

extern void stream_sp_sse_fma();

extern void stream_sse();

extern void stream_sse_fma();

extern void sum();

extern void sum_avx();

extern void sum_avx512();

extern void sum_sp();

extern void sum_sp_avx();

extern void sum_sp_avx512();

extern void sum_sp_sse();

extern void sum_sse();

extern void triad();

extern void triad_avx();

extern void triad_avx512();

extern void triad_avx512_fma();

extern void triad_avx_fma();

extern void triad_mem_avx();

extern void triad_mem_avx512();

extern void triad_mem_avx512_fma();

extern void triad_mem_avx_fma();

extern void triad_mem_sse();

extern void triad_mem_sse_fma();

extern void triad_sp();

extern void triad_sp_avx();

extern void triad_sp_avx512();

extern void triad_sp_avx512_fma();

extern void triad_sp_avx_fma();

extern void triad_sp_mem_avx();

extern void triad_sp_mem_avx512();

extern void triad_sp_mem_avx512_fma();

extern void triad_sp_mem_avx_fma();

extern void triad_sp_mem_sse();

extern void triad_sp_mem_sse_fma();

extern void triad_sp_sse();

extern void triad_sp_sse_fma();

extern void triad_sse();

extern void triad_sse_fma();

extern void update();

extern void update_avx();

extern void update_avx512();

extern void update_sp();

extern void update_sp_avx();

extern void update_sp_avx512();

extern void update_sp_sse();

extern void update_sse();


#define TESTS  "clcopy - Double-precision cache line copy, only touches first element of each cache line.\nclload - Double-precision cache line load, only loads first element of each cache line.\nclstore - Double-precision cache line store, only stores first element of each cache line.\ncopy - Double-precision vector copy, only scalar operations\ncopy_avx - Double-precision vector copy, optimized for AVX\ncopy_avx512 - Double-precision vector copy, optimized for AVX-\ncopy_mem - Double-precision vector copy, only scalar operations but with non-temporal stores\ncopy_mem_avx - Double-precision vector copy, uses AVX and non-temporal stores\ncopy_mem_avx512 - Double-precision vector copy, uses AVX-\ncopy_mem_sse - Double-precision vector copy, uses SSE and non-temporal stores\ncopy_sse - Double-precision vector copy, optimized for SSE\ndaxpy - Double-precision linear combination of two vectors, only scalar operations\ndaxpy_avx - Double-precision linear combination of two vectors, optimized for AVX\ndaxpy_avx512 - Double-precision linear combination of two vectors, optimized for AVX-\ndaxpy_avx512_fma - Double-precision linear combination of two vectors, optimized for AVX-\ndaxpy_avx_fma - Double-precision linear combination of two vectors, optimized for AVX FMAs\ndaxpy_mem_avx - Double-precision linear combination of two vectors, optimized for AVX and non-temporal stores (Just for architectural research)\ndaxpy_mem_avx512 - Double-precision linear combination of two vectors, optimized for AVX-\ndaxpy_mem_avx512_fma - Double-precision linear combination of two vectors, optimized for AVX-\ndaxpy_mem_avx_fma - Double-precision linear combination of two vectors, optimized for AVX FMAs and non-temporal stores (Just for architectural research)\ndaxpy_mem_sse - Double-precision linear combination of two vectors, optimized for SSE and non-temporal stores (Just for architectural research)\ndaxpy_mem_sse_fma - Double-precision linear combination of two vectors, optimized for SSE FMAs and non temporal stores (Just for architectural research)\ndaxpy_sp - Single-precision linear combination of two vectors, only scalar operations\ndaxpy_sp_avx - Single-precision linear combination of two vectors, optimized for AVX\ndaxpy_sp_avx512 - Single-precision linear combination of two vectors, optimized for AVX-\ndaxpy_sp_avx512_fma - Single-precision linear combination of two vectors, optimized for AVX-\ndaxpy_sp_avx_fma - Single-precision linear combination of two vectors, optimized for AVX FMAs\ndaxpy_sp_mem_avx - Single-precision linear combination of two vectors, optimized for AVX and non-temporal stores (Just for architectural research)\ndaxpy_sp_mem_avx512 - Single-precision linear combination of two vectors, optimized for AVX-\ndaxpy_sp_mem_avx512_fma - Single-precision linear combination of two vectors, optimized for AVX-\ndaxpy_sp_mem_avx_fma - Single-precision linear combination of two vectors, optimized for AVX FMAs and non-temporal stores (Just for architectural research)\ndaxpy_sp_mem_sse - Single-precision linear combination of two vectors, optimized for SSE and non-temporal stores (Just for architectural research)\ndaxpy_sp_mem_sse_fma - Single-precision linear combination of two vectors, optimized for SSE FMAs and non-temporal stores (Just for architectural research)\ndaxpy_sp_sse - Single-precision linear combination of two vectors, optimized for SSE\ndaxpy_sp_sse_fma - Single-precision linear combination of two vectors, optimized for SSE FMAs\ndaxpy_sse - Double-precision linear combination of two vectors, optimized for SSE\ndaxpy_sse_fma - Double-precision linear combination of two vectors, optimized for SSE FMAs\nddot - Double-precision dot product of two vectors, only scalar operations\nddot_avx - Double-precision dot product of two vectors, optimized for AVX\nddot_avx512 - Double-precision dot product of two vectors, optimized for AVX-\nddot_sp - Single-precision dot product of two vectors, only scalar operations\nddot_sp_avx - Single-precision dot product of two vectors, optimized for AVX\nddot_sp_avx512 - Single-precision dot product of two vectors, optimized for AVX-\nddot_sp_sse - Single-precision dot product of two vectors, optimized for SSE\nddot_sse - Double-precision dot product of two vectors, optimized for SSE\ndivide - Double-precision vector update, only scalar operations\nload - Double-precision load, only scalar operations\nload_avx - Double-precision load, optimized for AVX\nload_avx512 - Double-precision load, optimized for AVX-\nload_mem - Double-precision load, using non-temporal loads\nload_sse - Double-precision load, optimized for SSE\npeakflops - \npeakflops_avx - \npeakflops_sse - \nstore - Double-precision store, only scalar operations\nstore_avx - Double-precision store, optimized for AVX\nstore_avx512 - Double-precision store, optimized for AVX-\nstore_mem - Double-precision store, uses non-temporal stores\nstore_mem_avx - Double-precision store, uses AVX and non-temporal stores\nstore_mem_avx512 - Double-precision store, uses AVX-\nstore_mem_sse - Double-precision store, uses SSE and non-temporal stores\nstore_sse - Double-precision store, optimized for SSE\nstream - Double-precision stream triad A(i) = B(i)*c + C(i), only scalar operations\nstream_avx - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX\nstream_avx512 - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_avx512_fma - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_avx_fma - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs\nstream_mem - Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE and non-temporal stores\nstream_mem_avx - Double-precision stream triad A(i) = B(i)*c + C(i), uses AVX and non-temporal stores\nstream_mem_avx_fma - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs and non-temporal stores\nstream_mem_sse - Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE and non-temporal stores\nstream_mem_sse_fma - Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE FMAs and non-temporal stores\nstream_sp - Single-precision stream triad A(i) = B(i)*c + C(i), only scalar operations\nstream_sp_avx - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX\nstream_sp_avx512 - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_sp_avx512_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_sp_avx_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs\nstream_sp_mem_avx - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX and non-temporal stores\nstream_sp_mem_avx512 - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_sp_mem_avx512_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-\nstream_sp_mem_avx_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs and non-temporal stores\nstream_sp_mem_sse - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE and non-temporal stores\nstream_sp_mem_sse_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs and non-temporal stores\nstream_sp_sse - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE\nstream_sp_sse_fma - Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs\nstream_sse - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE\nstream_sse_fma - Double-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs\nsum - Double-precision sum of a vector, only scalar operations\nsum_avx - Double-precision sum of a vector, optimized for AVX\nsum_avx512 - Double-precision sum of a vector, optimized for AVX-\nsum_sp - Single-precision sum of a vector, only scalar operations\nsum_sp_avx - Single-precision sum of a vector, optimized for AVX\nsum_sp_avx512 - Single-precision sum of a vector, optimized for AVX-\nsum_sp_sse - Single-precision sum of a vector, optimized for SSE\nsum_sse - Double-precision sum of a vector, optimized for SSE\ntriad - Double-precision triad A(i) = B(i) * C(i) + D(i), only scalar operations\ntriad_avx - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX\ntriad_avx512 - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_avx512_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_avx_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs\ntriad_mem_avx - Double-precision triad A(i) = B(i) * C(i) + D(i), uses AVX and non-temporal stores\ntriad_mem_avx512 - Double-precision triad A(i) = B(i) * C(i) + D(i), uses AVX-\ntriad_mem_avx512_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_mem_avx_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs and non-temporal stores\ntriad_mem_sse - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE and non-temporal stores\ntriad_mem_sse_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs and non-temporal stores\ntriad_sp - Single-precision triad A(i) = B(i) * C(i) + D(i), only scalar operations\ntriad_sp_avx - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX\ntriad_sp_avx512 - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_sp_avx512_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_sp_avx_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs\ntriad_sp_mem_avx - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX and non-temporal stores\ntriad_sp_mem_avx512 - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_sp_mem_avx512_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-\ntriad_sp_mem_avx_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs and non-temporal stores\ntriad_sp_mem_sse - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE and non-temporal stores\ntriad_sp_mem_sse_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs and non-temporal stores\ntriad_sp_sse - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE\ntriad_sp_sse_fma - Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs\ntriad_sse - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE\ntriad_sse_fma - Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs\nupdate - Double-precision vector update, only scalar operations\nupdate_avx - Double-precision vector update, optimized for AVX\nupdate_avx512 - Double-precision vector update, optimized for AVX-\nupdate_sp - Single-precision vector update, only scalar operations\nupdate_sp_avx - Single-precision vector update, optimized for AVX\nupdate_sp_avx512 - Single-precision vector update, optimized for AVX-\nupdate_sp_sse - Single-precision vector update, optimized for SSE\nupdate_sse - Double-precision vector update, optimized for SSE"
#define NUMKERNELS 129

static const TestCase kernels[NUMKERNELS] = {
    
    {"clcopy" , STREAM_2, DOUBLE, 32, &clcopy, 0, 16, "Double-precision cache line copy, only touches first element of each cache line.", 1, 1, -1, 16, 11, 14},
    
    {"clload" , STREAM_1, DOUBLE, 32, &clload, 0, 8, "Double-precision cache line load, only loads first element of each cache line.", 1, 0, -1, 16, 7, 6},
    
    {"clstore" , STREAM_1, DOUBLE, 32, &clstore, 0, 8, "Double-precision cache line store, only stores first element of each cache line.", 0, 1, -1, 20, 7, 10},
    
    {"copy" , STREAM_2, DOUBLE, 4, &copy, 0, 16, "Double-precision vector copy, only scalar operations", 1, 1, -1, 16, 11, 14},
    
    {"copy_avx" , STREAM_2, DOUBLE, 16, &copy_avx, 0, 16, "Double-precision vector copy, optimized for AVX", 1, 1, -1, 16, 11, 14},
    
    {"copy_avx512" , STREAM_2, DOUBLE, 32, &copy_avx512, 0, 16, "Double-precision vector copy, optimized for AVX-", 1, 1, -1, 16, 11, 14},
    
    {"copy_mem" , STREAM_2, DOUBLE, 4, &copy_mem, 0, 16, "Double-precision vector copy, only scalar operations but with non-temporal stores", 1, 1, -1, 16, 11, 14},
    
    {"copy_mem_avx" , STREAM_2, DOUBLE, 16, &copy_mem_avx, 0, 16, "Double-precision vector copy, uses AVX and non-temporal stores", 1, 1, -1, 16, 11, 14},
    
    {"copy_mem_avx512" , STREAM_2, DOUBLE, 32, &copy_mem_avx512, 0, 16, "Double-precision vector copy, uses AVX-", 1, 1, -1, 16, 11, 14},
    
    {"copy_mem_sse" , STREAM_2, DOUBLE, 8, &copy_mem_sse, 0, 16, "Double-precision vector copy, uses SSE and non-temporal stores", 1, 1, -1, 16, 11, 14},
    
    {"copy_sse" , STREAM_2, DOUBLE, 8, &copy_sse, 0, 16, "Double-precision vector copy, optimized for SSE", 1, 1, -1, 16, 11, 14},
    
    {"daxpy" , STREAM_2, DOUBLE, 4, &daxpy, 2, 24, "Double-precision linear combination of two vectors, only scalar operations", 2, 1, -1, 17, 19, 26},
    
    {"daxpy_avx" , STREAM_2, DOUBLE, 24, &daxpy_avx, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX", 2, 1, -1, 17, 21, 38},
    
    {"daxpy_avx512" , STREAM_2, DOUBLE, 32, &daxpy_avx512, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 21, 38},
    
    {"daxpy_avx512_fma" , STREAM_2, DOUBLE, 32, &daxpy_avx512_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_avx_fma" , STREAM_2, DOUBLE, 16, &daxpy_avx_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX FMAs", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_mem_avx" , STREAM_2, DOUBLE, 24, &daxpy_mem_avx, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 21, 38},
    
    {"daxpy_mem_avx512" , STREAM_2, DOUBLE, 32, &daxpy_mem_avx512, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 14, 22},
    
    {"daxpy_mem_avx512_fma" , STREAM_2, DOUBLE, 32, &daxpy_mem_avx512_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_mem_avx_fma" , STREAM_2, DOUBLE, 16, &daxpy_mem_avx_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for AVX FMAs and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_mem_sse" , STREAM_2, DOUBLE, 8, &daxpy_mem_sse, 2, 24, "Double-precision linear combination of two vectors, optimized for SSE and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 15, 26},
    
    {"daxpy_mem_sse_fma" , STREAM_2, DOUBLE, 8, &daxpy_mem_sse_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for SSE FMAs and non temporal stores (Just for architectural research)", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp" , STREAM_2, SINGLE, 8, &daxpy_sp, 2, 12, "Single-precision linear combination of two vectors, only scalar operations", 2, 1, -1, 17, 32, 50},
    
    {"daxpy_sp_avx" , STREAM_2, SINGLE, 16, &daxpy_sp_avx, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX", 2, 1, -1, 17, 9, 14},
    
    {"daxpy_sp_avx512" , STREAM_2, SINGLE, 32, &daxpy_sp_avx512, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 9, 14},
    
    {"daxpy_sp_avx512_fma" , STREAM_2, SINGLE, 64, &daxpy_sp_avx512_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp_avx_fma" , STREAM_2, SINGLE, 32, &daxpy_sp_avx_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX FMAs", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp_mem_avx" , STREAM_2, SINGLE, 16, &daxpy_sp_mem_avx, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 9, 14},
    
    {"daxpy_sp_mem_avx512" , STREAM_2, SINGLE, 32, &daxpy_sp_mem_avx512, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 9, 14},
    
    {"daxpy_sp_mem_avx512_fma" , STREAM_2, SINGLE, 64, &daxpy_sp_mem_avx512_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp_mem_avx_fma" , STREAM_2, SINGLE, 32, &daxpy_sp_mem_avx_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for AVX FMAs and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp_mem_sse" , STREAM_2, SINGLE, 8, &daxpy_sp_mem_sse, 2, 12, "Single-precision linear combination of two vectors, optimized for SSE and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 11, 14},
    
    {"daxpy_sp_mem_sse_fma" , STREAM_2, SINGLE, 32, &daxpy_sp_mem_sse_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for SSE FMAs and non-temporal stores (Just for architectural research)", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sp_sse" , STREAM_2, SINGLE, 16, &daxpy_sp_sse, 2, 12, "Single-precision linear combination of two vectors, optimized for SSE", 2, 1, -1, 17, 19, 26},
    
    {"daxpy_sp_sse_fma" , STREAM_2, SINGLE, 32, &daxpy_sp_sse_fma, 2, 12, "Single-precision linear combination of two vectors, optimized for SSE FMAs", 2, 1, -1, 17, 15, 22},
    
    {"daxpy_sse" , STREAM_2, DOUBLE, 8, &daxpy_sse, 2, 24, "Double-precision linear combination of two vectors, optimized for SSE", 2, 1, -1, 17, 19, 26},
    
    {"daxpy_sse_fma" , STREAM_2, DOUBLE, 8, &daxpy_sse_fma, 2, 24, "Double-precision linear combination of two vectors, optimized for SSE FMAs", 2, 1, -1, 17, 15, 22},
    
    {"ddot" , STREAM_2, DOUBLE, 4, &ddot, 2, 16, "Double-precision dot product of two vectors, only scalar operations", 2, 0, -1, 20, 15, 18},
    
    {"ddot_avx" , STREAM_2, DOUBLE, 16, &ddot_avx, 2, 16, "Double-precision dot product of two vectors, optimized for AVX", 2, 0, -1, 20, 15, 18},
    
    {"ddot_avx512" , STREAM_2, DOUBLE, 32, &ddot_avx512, 2, 16, "Double-precision dot product of two vectors, optimized for AVX-", 2, 0, -1, 20, 15, 18},
    
    {"ddot_sp" , STREAM_2, SINGLE, 4, &ddot_sp, 2, 8, "Single-precision dot product of two vectors, only scalar operations", 2, 0, -1, 20, 15, 18},
    
    {"ddot_sp_avx" , STREAM_2, SINGLE, 16, &ddot_sp_avx, 2, 8, "Single-precision dot product of two vectors, optimized for AVX", 2, 0, -1, 18, 9, 10},
    
    {"ddot_sp_avx512" , STREAM_2, SINGLE, 32, &ddot_sp_avx512, 2, 8, "Single-precision dot product of two vectors, optimized for AVX-", 2, 0, -1, 18, 9, 10},
    
    {"ddot_sp_sse" , STREAM_2, SINGLE, 8, &ddot_sp_sse, 2, 8, "Single-precision dot product of two vectors, optimized for SSE", 2, 0, -1, 18, 9, 10},
    
    {"ddot_sse" , STREAM_2, DOUBLE, 8, &ddot_sse, 2, 16, "Double-precision dot product of two vectors, optimized for SSE", 2, 0, -1, 20, 15, 18},
    
    {"divide" , STREAM_1, DOUBLE, 4, &divide, 1, 16, "Double-precision vector update, only scalar operations", 1, 1, -1, 16, 11, 14},
    
    {"load" , STREAM_1, DOUBLE, 8, &load, 0, 8, "Double-precision load, only scalar operations", 1, 0, -1, 16, 11, 10},
    
    {"load_avx" , STREAM_1, DOUBLE, 16, &load_avx, 0, 8, "Double-precision load, optimized for AVX", 1, 0, -1, 16, 7, 6},
    
    {"load_avx512" , STREAM_1, DOUBLE, 32, &load_avx512, 0, 8, "Double-precision load, optimized for AVX-", 1, 0, -1, 16, 7, 6},
    
    {"load_mem" , STREAM_1, DOUBLE, 8, &load_mem, 0, 8, "Double-precision load, using non-temporal loads", 1, 0, -1, 16, 7, 6},
    
    {"load_sse" , STREAM_1, DOUBLE, 8, &load_sse, 0, 8, "Double-precision load, optimized for SSE", 1, 0, -1, 16, 7, 6},
    
    {"peakflops" , STREAM_1, DOUBLE, 1, &peakflops, 8, 8, "", -1, -1, -1, -1, -1, -1},
    
    {"peakflops_avx" , STREAM_1, DOUBLE, 4, &peakflops_avx, 8, 8, "", -1, -1, -1, -1, -1, -1},
    
    {"peakflops_sse" , STREAM_1, DOUBLE, 2, &peakflops_sse, 8, 8, "", -1, -1, -1, -1, -1, -1},
    
    {"store" , STREAM_1, DOUBLE, 4, &store, 0, 8, "Double-precision store, only scalar operations", 0, 1, -1, 20, 7, 10},
    
    {"store_avx" , STREAM_1, DOUBLE, 16, &store_avx, 0, 8, "Double-precision store, optimized for AVX", 0, 1, -1, 20, 7, 10},
    
    {"store_avx512" , STREAM_1, DOUBLE, 32, &store_avx512, 0, 8, "Double-precision store, optimized for AVX-", 0, 1, -1, 20, 7, 10},
    
    {"store_mem" , STREAM_1, DOUBLE, 8, &store_mem, 0, 8, "Double-precision store, uses non-temporal stores", 0, 1, -1, 20, 7, 10},
    
    {"store_mem_avx" , STREAM_1, DOUBLE, 16, &store_mem_avx, 0, 8, "Double-precision store, uses AVX and non-temporal stores", 0, 1, -1, 20, 7, 10},
    
    {"store_mem_avx512" , STREAM_1, DOUBLE, 32, &store_mem_avx512, 0, 8, "Double-precision store, uses AVX-", 0, 1, -1, 20, 7, 10},
    
    {"store_mem_sse" , STREAM_1, DOUBLE, 8, &store_mem_sse, 0, 8, "Double-precision store, uses SSE and non-temporal stores", 0, 1, -1, 20, 7, 10},
    
    {"store_sse" , STREAM_1, DOUBLE, 8, &store_sse, 0, 8, "Double-precision store, optimized for SSE", 0, 1, -1, 20, 7, 10},
    
    {"stream" , STREAM_3, DOUBLE, 4, &stream, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), only scalar operations", 2, 1, -1, 17, 19, 26},
    
    {"stream_avx" , STREAM_3, DOUBLE, 16, &stream_avx, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX", 2, 1, -1, 17, 19, 26},
    
    {"stream_avx512" , STREAM_3, DOUBLE, 32, &stream_avx512, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 19, 26},
    
    {"stream_avx512_fma" , STREAM_3, DOUBLE, 32, &stream_avx512_fma, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"stream_avx_fma" , STREAM_3, DOUBLE, 16, &stream_avx_fma, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs", 2, 1, -1, 17, 15, 22},
    
    {"stream_mem" , STREAM_3, DOUBLE, 4, &stream_mem, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE and non-temporal stores", 2, 1, -1, 17, 7, 8},
    
    {"stream_mem_avx" , STREAM_3, DOUBLE, 4, &stream_mem_avx, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), uses AVX and non-temporal stores", 2, 1, -1, 17, 7, 8},
    
    {"stream_mem_avx_fma" , STREAM_3, DOUBLE, 16, &stream_mem_avx_fma, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs and non-temporal stores", 2, 1, -1, 17, 15, 22},
    
    {"stream_mem_sse" , STREAM_3, DOUBLE, 2, &stream_mem_sse, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE and non-temporal stores", 2, 1, -1, 17, 7, 8},
    
    {"stream_mem_sse_fma" , STREAM_3, DOUBLE, 2, &stream_mem_sse_fma, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), uses SSE FMAs and non-temporal stores", 2, 1, -1, 17, 6, 7},
    
    {"stream_sp" , STREAM_3, SINGLE, 8, &stream_sp, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), only scalar operations", 2, 1, -1, 17, 35, 50},
    
    {"stream_sp_avx" , STREAM_3, SINGLE, 32, &stream_sp_avx, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX", 2, 1, -1, 17, 19, 26},
    
    {"stream_sp_avx512" , STREAM_3, SINGLE, 64, &stream_sp_avx512, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 19, 26},
    
    {"stream_sp_avx512_fma" , STREAM_3, SINGLE, 64, &stream_sp_avx512_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"stream_sp_avx_fma" , STREAM_3, SINGLE, 32, &stream_sp_avx_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs", 2, 1, -1, 17, 15, 22},
    
    {"stream_sp_mem_avx" , STREAM_3, SINGLE, 32, &stream_sp_mem_avx, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX and non-temporal stores", 2, 1, -1, 17, 19, 26},
    
    {"stream_sp_mem_avx512" , STREAM_3, SINGLE, 64, &stream_sp_mem_avx512, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 19, 26},
    
    {"stream_sp_mem_avx512_fma" , STREAM_3, SINGLE, 64, &stream_sp_mem_avx512_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX-", 2, 1, -1, 17, 15, 22},
    
    {"stream_sp_mem_avx_fma" , STREAM_3, SINGLE, 32, &stream_sp_mem_avx_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for AVX FMAs and non-temporal stores", 2, 1, -1, 17, 15, 22},
    
    {"stream_sp_mem_sse" , STREAM_3, SINGLE, 4, &stream_sp_mem_sse, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE and non-temporal stores", 2, 1, -1, 17, 7, 8},
    
    {"stream_sp_mem_sse_fma" , STREAM_3, SINGLE, 4, &stream_sp_mem_sse_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs and non-temporal stores", 2, 1, -1, 17, 6, 7},
    
    {"stream_sp_sse" , STREAM_3, SINGLE, 4, &stream_sp_sse, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE", 2, 1, -1, 17, 7, 8},
    
    {"stream_sp_sse_fma" , STREAM_3, SINGLE, 4, &stream_sp_sse_fma, 2, 12, "Single-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs", 2, 1, -1, 17, 6, 7},
    
    {"stream_sse" , STREAM_3, DOUBLE, 8, &stream_sse, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE", 2, 1, -1, 17, 19, 26},
    
    {"stream_sse_fma" , STREAM_3, DOUBLE, 8, &stream_sse_fma, 2, 24, "Double-precision stream triad A(i) = B(i)*c + C(i), optimized for SSE FMAs", 2, 1, -1, 17, 15, 22},
    
    {"sum" , STREAM_1, DOUBLE, 8, &sum, 1, 8, "Double-precision sum of a vector, only scalar operations", 1, 0, -1, 24, 11, 18},
    
    {"sum_avx" , STREAM_1, DOUBLE, 32, &sum_avx, 1, 8, "Double-precision sum of a vector, optimized for AVX", 1, 0, -1, 24, 11, 18},
    
    {"sum_avx512" , STREAM_1, DOUBLE, 64, &sum_avx512, 1, 8, "Double-precision sum of a vector, optimized for AVX-", 1, 0, -1, 24, 11, 18},
    
    {"sum_sp" , STREAM_1, SINGLE, 4, &sum_sp, 1, 4, "Single-precision sum of a vector, only scalar operations", 1, 0, -1, 20, 7, 10},
    
    {"sum_sp_avx" , STREAM_1, SINGLE, 32, &sum_sp_avx, 1, 4, "Single-precision sum of a vector, optimized for AVX", 1, 0, -1, 20, 7, 10},
    
    {"sum_sp_avx512" , STREAM_1, SINGLE, 64, &sum_sp_avx512, 1, 4, "Single-precision sum of a vector, optimized for AVX-", 1, 0, -1, 20, 7, 10},
    
    {"sum_sp_sse" , STREAM_1, SINGLE, 32, &sum_sp_sse, 1, 4, "Single-precision sum of a vector, optimized for SSE", 1, 0, -1, 24, 11, 18},
    
    {"sum_sse" , STREAM_1, DOUBLE, 16, &sum_sse, 1, 8, "Double-precision sum of a vector, optimized for SSE", 1, 0, -1, 24, 11, 18},
    
    {"triad" , STREAM_4, DOUBLE, 4, &triad, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), only scalar operations", 3, 1, -1, 16, 19, 30},
    
    {"triad_avx" , STREAM_4, DOUBLE, 16, &triad_avx, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX", 3, 1, -1, 16, 19, 30},
    
    {"triad_avx512" , STREAM_4, DOUBLE, 32, &triad_avx512, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 19, 30},
    
    {"triad_avx512_fma" , STREAM_4, DOUBLE, 32, &triad_avx512_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 19, 26},
    
    {"triad_avx_fma" , STREAM_4, DOUBLE, 16, &triad_avx_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs", 3, 1, -1, 16, 19, 26},
    
    {"triad_mem_avx" , STREAM_4, DOUBLE, 4, &triad_mem_avx, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), uses AVX and non-temporal stores", 3, 1, -1, 16, 9, 9},
    
    {"triad_mem_avx512" , STREAM_4, DOUBLE, 8, &triad_mem_avx512, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), uses AVX-", 3, 1, -1, 16, 9, 9},
    
    {"triad_mem_avx512_fma" , STREAM_4, DOUBLE, 16, &triad_mem_avx512_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 11, 14},
    
    {"triad_mem_avx_fma" , STREAM_4, DOUBLE, 8, &triad_mem_avx_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs and non-temporal stores", 3, 1, -1, 16, 11, 14},
    
    {"triad_mem_sse" , STREAM_4, DOUBLE, 8, &triad_mem_sse, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE and non-temporal stores", 3, 1, -1, 16, 19, 30},
    
    {"triad_mem_sse_fma" , STREAM_4, DOUBLE, 8, &triad_mem_sse_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs and non-temporal stores", 3, 1, -1, 16, 19, 26},
    
    {"triad_sp" , STREAM_4, SINGLE, 8, &triad_sp, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), only scalar operations", 3, 1, -1, 16, 35, 58},
    
    {"triad_sp_avx" , STREAM_4, SINGLE, 8, &triad_sp_avx, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX", 3, 1, -1, 16, 9, 9},
    
    {"triad_sp_avx512" , STREAM_4, SINGLE, 16, &triad_sp_avx512, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 9, 9},
    
    {"triad_sp_avx512_fma" , STREAM_4, SINGLE, 16, &triad_sp_avx512_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 7, 8},
    
    {"triad_sp_avx_fma" , STREAM_4, SINGLE, 8, &triad_sp_avx_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs", 3, 1, -1, 16, 7, 8},
    
    {"triad_sp_mem_avx" , STREAM_4, SINGLE, 8, &triad_sp_mem_avx, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX and non-temporal stores", 3, 1, -1, 16, 9, 9},
    
    {"triad_sp_mem_avx512" , STREAM_4, SINGLE, 16, &triad_sp_mem_avx512, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 9, 9},
    
    {"triad_sp_mem_avx512_fma" , STREAM_4, SINGLE, 16, &triad_sp_mem_avx512_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX-", 3, 1, -1, 16, 7, 8},
    
    {"triad_sp_mem_avx_fma" , STREAM_4, SINGLE, 8, &triad_sp_mem_avx_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for AVX FMAs and non-temporal stores", 3, 1, -1, 16, 7, 8},
    
    {"triad_sp_mem_sse" , STREAM_4, SINGLE, 16, &triad_sp_mem_sse, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE and non-temporal stores", 3, 1, -1, 16, 19, 30},
    
    {"triad_sp_mem_sse_fma" , STREAM_4, SINGLE, 16, &triad_sp_mem_sse_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs and non-temporal stores", 3, 1, -1, 16, 19, 30},
    
    {"triad_sp_sse" , STREAM_4, SINGLE, 16, &triad_sp_sse, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE", 3, 1, -1, 16, 19, 30},
    
    {"triad_sp_sse_fma" , STREAM_4, SINGLE, 16, &triad_sp_sse_fma, 2, 16, "Single-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs", 3, 1, -1, 16, 19, 30},
    
    {"triad_sse" , STREAM_4, DOUBLE, 8, &triad_sse, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE", 3, 1, -1, 16, 19, 30},
    
    {"triad_sse_fma" , STREAM_4, DOUBLE, 8, &triad_sse_fma, 2, 32, "Double-precision triad A(i) = B(i) * C(i) + D(i), optimized for SSE FMAs", 3, 1, -1, 16, 19, 26},
    
    {"update" , STREAM_1, DOUBLE, 4, &update, 0, 16, "Double-precision vector update, only scalar operations", 1, 1, -1, 16, 11, 14},
    
    {"update_avx" , STREAM_1, DOUBLE, 16, &update_avx, 0, 16, "Double-precision vector update, optimized for AVX", 1, 1, -1, 16, 11, 14},
    
    {"update_avx512" , STREAM_1, DOUBLE, 32, &update_avx512, 0, 16, "Double-precision vector update, optimized for AVX-", 1, 1, -1, 16, 11, 14},
    
    {"update_sp" , STREAM_1, SINGLE, 4, &update_sp, 0, 8, "Single-precision vector update, only scalar operations", 1, 1, -1, 16, 11, 14},
    
    {"update_sp_avx" , STREAM_1, SINGLE, 32, &update_sp_avx, 0, 8, "Single-precision vector update, optimized for AVX", 1, 1, -1, 16, 11, 14},
    
    {"update_sp_avx512" , STREAM_1, SINGLE, 64, &update_sp_avx512, 0, 8, "Single-precision vector update, optimized for AVX-", 1, 1, -1, 16, 11, 14},
    
    {"update_sp_sse" , STREAM_1, SINGLE, 16, &update_sp_sse, 0, 8, "Single-precision vector update, optimized for SSE", 1, 1, -1, 16, 11, 14},
    
    {"update_sse" , STREAM_1, DOUBLE, 8, &update_sse, 0, 16, "Double-precision vector update, optimized for SSE", 1, 1, -1, 16, 11, 14},
    
};

#endif /* TESTCASES_H */
