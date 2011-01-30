/*
 * Copyright 2009   Cosmin Cojocar <cosmin.cojocar@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include "cpu_usage.h"

int main(int argc, char **argv)
{
  struct cpu_counters cpu_cnt_start, cpu_cnt_end;

  read_cpu_counters(&cpu_cnt_start);
  printf("start: total jiffies = %lld, work jiffies = %lld\n",
    cpu_cnt_start.total_jiffies, cpu_cnt_start.work_jiffies);

  int i = 120;
  while (i--)
    sleep(1);

  read_cpu_counters(&cpu_cnt_end);
  printf("end: total jiffies = %lld, work jiffies = %lld\n",
      cpu_cnt_end.total_jiffies, cpu_cnt_end.work_jiffies);

  printf("cpu usage = %3.2f\n", cpu_usage(&cpu_cnt_start, &cpu_cnt_end));

  return 0;
}
