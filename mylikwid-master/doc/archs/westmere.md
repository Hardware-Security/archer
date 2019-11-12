/*! \page westmere Intel&reg; Westmere

<P>The Intel&reg; Westmere microarchitecture has the same features as the Intel&reg; Nehalem architecture. There are some additional features like a second OFFCORE_RESPONSE register and an addr/opcode matching unit for general-purpose counters in the Uncore.</P>

<H1>Available performance monitors for the Intel&reg; Westmere microarchitecture</H1>
<UL>
<LI>\ref WES_FIXED "Fixed-purpose counters"</LI>
<LI>\ref WES_PMC "General-purpose counters"</LI>
<LI>\ref WES_UNCORE "Uncore counters"</LI>
</UL>

<H1>Counters available for each hardware thread</H1>
\anchor WES_FIXED
<H2>Fixed-purpose counters</H2>
<P>Since the Core2 microarchitecture, Intel&reg; provides a set of fixed-purpose counters. Each can measure only one specific event.</P>
<H3>Counter and events</H3>
<TABLE>
<TR>
  <TH>Counter name</TH>
  <TH>Event name</TH>
</TR>
<TR>
  <TD>FIXC0</TD>
  <TD>INSTR_RETIRED_ANY</TD>
</TR>
<TR>
  <TD>FIXC1</TD>
  <TD>CPU_CLK_UNHALTED_CORE</TD>
</TR>
<TR>
  <TD>FIXC2</TD>
  <TD>CPU_CLK_UNHALTED_REF</TD>
</TR>
</TABLE>
<H3>Available Options</H3>
<TABLE>
<TR>
  <TH>Option</TH>
  <TH>Argument</TH>
  <TH>Description</TH>
  <TH>Comment</TH>
</TR>
<TR>
  <TD>anythread</TD>
  <TD>N</TD>
  <TD>Set bit 2+(index*4) in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>kernel</TD>
  <TD>N</TD>
  <TD>Set bit (index*4) in config register</TD>
  <TD></TD>
</TR>
</TABLE>

\anchor WES_PMC
<H2>General-purpose counters</H2>
<P>The Intel&reg; Westmere microarchitecture provides 4 general-purpose counters consisting of a config and a counter register.</P>
<H3>Counter and events</H3>
<TABLE>
<TR>
  <TH>Counter name</TH>
  <TH>Event name</TH>
</TR>
<TR>
  <TD>PMC0</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>PMC1</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>PMC2</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>PMC3</TD>
  <TD>*</TD>
</TR>
</TABLE>
<H3>Available Options</H3>
<TABLE>
<TR>
  <TH>Option</TH>
  <TH>Argument</TH>
  <TH>Description</TH>
  <TH>Comment</TH>
</TR>
<TR>
  <TD>edgedetect</TD>
  <TD>N</TD>
  <TD>Set bit 18 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>kernel</TD>
  <TD>N</TD>
  <TD>Set bit 17 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>anythread</TD>
  <TD>N</TD>
  <TD>Set bit 21 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>threshold</TD>
  <TD>8 bit hex value</TD>
  <TD>Set bits 24-31 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>invert</TD>
  <TD>N</TD>
  <TD>Set bit 23 in config register</TD>
  <TD></TD>
</TR>
</TABLE>

<H3>Special handling for events</H3>
<P>The Intel&reg; Westmere microarchitecture provides measuring of offcore events in PMC counters. Therefore the stream of offcore events must be filtered using the OFFCORE_RESPONSE registers. The Intel&reg; Westmere microarchitecture has two of those registers. Own filtering can be applied with the OFFCORE_RESPONSE_0_OPTIONS and OFFCORE_RESPONSE_1_OPTIONS events. Only for those events two more counter options are available:</P>
<TABLE>
<TR>
  <TH>Option</TH>
  <TH>Argument</TH>
  <TH>Description</TH>
  <TH>Comment</TH>
</TR>
<TR>
  <TD>match0</TD>
  <TD>8 bit hex value</TD>
  <TD>Input value masked with 0xFF and written to bits 0-7 in the OFFCORE_RESPONSE register</TD>
  <TD>Check the <A HREF="http://www.Intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html">Intel&reg; Software Developer System Programming Manual, Vol. 3, Chapter Performance Monitoring</A> and <A HREF="https://download.01.org/perfmon/WSM-EP-SP">https://download.01.org/perfmon/WSM-EP-SP</A>.</TD>
</TR>
<TR>
  <TD>match1</TD>
  <TD>8 bit hex value</TD>
  <TD>Input value masked with 0xF7 and written to bits 8-15 in the OFFCORE_RESPONSE register</TD>
  <TD>Check the <A HREF="http://www.Intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html">Intel&reg; Software Developer System Programming Manual, Vol. 3, Chapter Performance Monitoring</A> and <A HREF="https://download.01.org/perfmon/WSM-EP-SP">https://download.01.org/perfmon/WSM-EP-SP</A>.</TD>
</TR>
</TABLE>

<H1>Counters available for one hardware thread per socket</H1>
\anchor WES_UNCORE
<H2>Uncore counters</H2>
<P>The Intel&reg; Westmere microarchitecture provides 8 general-purpose counters for the uncpre consisting of a config and a counter register. Moreover, there is a fixed-purpose counter to measure the clock of the uncore.</P>
<H3>Counter and events</H3>
<TABLE>
<TR>
  <TH>Counter name</TH>
  <TH>Event name</TH>
</TR>
<TR>
  <TD>UPMC0</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC1</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC2</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC3</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC4</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC5</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC6</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMC7</TD>
  <TD>*</TD>
</TR>
<TR>
  <TD>UPMCFIX</TD>
  <TD>UNCORE_CLOCKTICKS</TD>
</TR>
</TABLE>
<H3>Available Options (Only for UPMC<0-7> counters)</H3>
<TABLE>
<TR>
  <TH>Option</TH>
  <TH>Argument</TH>
  <TH>Description</TH>
  <TH>Comment</TH>
</TR>
<TR>
  <TD>edgedetect</TD>
  <TD>N</TD>
  <TD>Set bit 18 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>anythread</TD>
  <TD>N</TD>
  <TD>Set bit 21 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>threshold</TD>
  <TD>8 bit hex value</TD>
  <TD>Set bits 24-31 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>invert</TD>
  <TD>N</TD>
  <TD>Set bit 23 in config register</TD>
  <TD></TD>
</TR>
<TR>
  <TD>opcode</TD>
  <TD>8 bit hex value</TD>
  <TD>Set bits 40-47 in MSR_UNCORE_ADDR_OPCODE_MATCH register</TD>
  <TD>A list of valid opcodes can be found in the <A HREF="http://www.Intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html">Intel&reg; Software Developer System Programming Manual, Vol. 3, Chapter Performance Monitoring</A>.</TD>
</TR>
<TR>
  <TD>match0</TD>
  <TD>40 bit physical memory address</TD>
  <TD>Extract bits 3-39 from address and write them to bits 3-39 in MSR_UNCORE_ADDR_OPCODE_MATCH register</TD>
  <TD></TD>
</TR>
</TABLE>

*/
