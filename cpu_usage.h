/*
 * Copyright 2009   Cosmin Cojocar <cosmin.cojocar@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef CPU_USAGE_H
#define CPU_USAGE_H

struct cpu_counters {
  long long total_jiffies;
  long long work_jiffies;
};

/* reads the current cpu counters from /proc/stat */
int read_cpu_counters(struct cpu_counters *cpu_cnt);

/* returns the cpu usage in percent */
float cpu_usage(const struct cpu_counters *cpu_cnt_start,
        const struct cpu_counters *cpu_cnt_end);

#endif
