/*! \page silvermont Intel&reg; Silvermont/Airmont

<H1>Available performance monitors for the Intel&reg; Silvermont microarchitecture</H1>
<UL>
<LI>\ref SVM_FIXED "Fixed-purpose counters"</LI>
<LI>\ref SVM_PMC "General-purpose counters"</LI>
<LI>\ref SVM_THERMAL "Thermal counters"</LI>
<LI>\ref SVM_POWER "Power measurement counters"</LI>
</UL>

<H1>Counters available for each hardware thread</H1>
\anchor SVM_FIXED
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

\anchor SVM_PMC
<H2>General-purpose counters</H2>
<P>The Intel&reg; Silvermont microarchitecture provides 2 general-purpose counters consisting of a config and a counter register.</P>
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
<P>The Intel&reg; Silvermont microarchitecture provides measuring of offcore events in PMC counters. Therefore the stream of offcore events must be filtered using the OFFCORE_RESPONSE registers. The Intel&reg; Silvermont microarchitecture has two of those registers. LIKWID defines some events that perform the filtering according to the event name. Although there are many bitmasks possible, LIKWID natively provides only the ones with response type ANY. Own filtering can be applied with the OFFCORE_RESPONSE_0_OPTIONS and OFFCORE_RESPONSE_1_OPTIONS events. Only OFFCORE_RESPONSE_0_OPTIONS can be used to measure average latencies. Only for those events two more counter options are available:
</P>
<TABLE>
<TR>
  <TH>Option</TH>
  <TH>Argument</TH>
  <TH>Description</TH>
  <TH>Comment</TH>
</TR>
<TR>
  <TD>match0</TD>
  <TD>16 bit hex value</TD>
  <TD>Input value masked with 0xFFFF and written to bits 0-15 in the OFFCORE_RESPONSE register</TD>
  <TD>Check the <A HREF="http://www.Intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html">Intel&reg; Software Developer System Programming Manual, Vol. 3, Chapter Performance Monitoring</A> and <A HREF="https://download.01.org/perfmon/SLM">https://download.01.org/perfmon/SLM</A>.</TD>
</TR>
<TR>
  <TD>match1</TD>
  <TD>22 bit hex value</TD>
  <TD>Input value is written to bits 16-38 in the OFFCORE_RESPONSE register</TD>
  <TD>Check the <A HREF="http://www.Intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html">Intel&reg; Software Developer System Programming Manual, Vol. 3, Chapter Performance Monitoring</A> and <A HREF="https://download.01.org/perfmon/SLM">https://download.01.org/perfmon/SLM</A>.</TD>
</TR>
</TABLE>

\anchor SVM_THERMAL
<H2>Thermal counter</H2>
<P>The Intel&reg; Silvermont microarchitecture provides one register for the current core temperature.</P>
<H3>Counter and events</H3>
<TABLE>
<TR>
  <TH>Counter name</TH>
  <TH>Event name</TH>
</TR>
<TR>
  <TD>TMP0</TD>
  <TD>TEMP_CORE</TD>
</TR>
</TABLE>

<H1>Counters available for one hardware thread per socket</H1>
\anchor SVM_POWER
<H2>Power counters</H2>
<P>The Intel&reg; Silvermont microarchitecture provides measurements of the current power consumption through the RAPL interface.</P>
<H3>Counter and events</H3>
<TABLE>
<TR>
  <TH>Counter name</TH>
  <TH>Event name</TH>
</TR>
<TR>
  <TD>PWR0</TD>
  <TD>PWR_PKG_ENERGY</TD>
</TR>
<TR>
  <TD>PWR1</TD>
  <TD>PWR_PP0_ENERGY</TD>
</TR>
<TR>
  <TD>PWR2*</TD>
  <TD>PWR_PP1_ENERGY</TD>
</TR>
<TR>
  <TD>PWR3*</TD>
  <TD>PWR_DRAM_ENERGY</TD>
</TR>
</TABLE>
<P>*) The PWR2 and PWR3 counter is commonly not implemented by Intel&reg; Silvermont systems.</P>
*/
