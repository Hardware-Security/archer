# The Archer - [The] Micro[arch]itecture Analyz[er]
This repository contains the code for the archer paper, our microarchitecture analyzer.

# Description 
In  this  work,  we  want  to  analyze  the  microcodes  of each instruction after and before any microcode update and
find  the  differences  caused  by  microcode  updates,  MSR modifications, and control registers transitions to find where
intel  attempts  to  patch  during  its  microcode  updates  and to  discover  other  possible  vulnerabilities.  Then,  we  try  to find vulnerabilities that result in these changes.

# Examples 
For example,our experiments show that instruction X previously takes n cycles;  now,  it  needs (n+i) cycles  to  do  the  same  job.
Also,  its  micro-Op  count  is  changed.  For  example,  if  we assume  that  a  microcode  update  is  related  to  CFLUSH,
before applying this update, we forced the cache to be in a specific state (flushed and filled), then we test the execution
of CFLUSH and get the results about its behavior. After that, we  update  our  processor  using  the  microcode  update.  Our
results in terms of the performance counter, which are related to  L1,  L2,  and  L3  cache,  also  iTLB  and  dTLB  changed
significantly.  This  observation  can  confirm  our  assumption about patched instruction. Even we could not precisely find
where  they  had  patched,  but  the  features  show  that  cache events and some port-related features changed so by knowing
these  details  we  can  somehow  understand  what  kind  of components they try to change. We will use some machine
learning  approaches  to  find  the  origin  of  the  changes;  then we  try  to  find  other  instructions  with  similar  features  that might be translated to similar vulnerability. In the last step, we may try to compromise the system using instructions with similar features to the patched instructions.

## ArcherDatabases
This directory contains the SQL definition (.sql file) in order to create database (tables) for storing the results of the analyzer. There is also GetTableFromResultsToHTML.py which converts the database results into a human readable HTML Table.

## ArcherLikwid
ArcherLikwid is customized build of the Likwid designed to use Hardware Performance Counters and combine all the possible HPCs with Intel TSX (Intel Transactional Synchronization Extensions Technology), it reads the possible instruction from the results of ArcherSandsifter.

## ArcherMSRManager
ArcherMSRManager is used to brute-force over MSRs in order to find new instruction which appears in the result of activating a MSR bit and finding the odd behaviors over the different MSRs. It uses ArcherTransferOverUSB as the transfer module to send the data about MSRs into database.

## ArcherNanoBench
## ArcherSampleResults
## ArcherSandsifter
## ArcherTransferOverUSB
