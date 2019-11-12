/*
 * =======================================================================================
 *
 *      Filename:  topology_cpuid.h
 *
 *      Description:  Header File of topology backend using cpuid instruction.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:   Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2016 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */
#ifndef TOPOLOGY_CPUID_H
#define TOPOLOGY_CPUID_H

#include <sched.h>

void cpuid_init_cpuInfo(cpu_set_t cpuSet);
void cpuid_init_cpuFeatures(void);
void cpuid_init_nodeTopology(cpu_set_t cpuSet);
void cpuid_init_cacheTopology(void);

#endif /* TOPOLOGY_CPUID_H */
