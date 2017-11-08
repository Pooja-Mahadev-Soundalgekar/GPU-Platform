#!/bin/env bash

#SBATCH --job-name=test_OpenCL_cpu
#SBATCH --partition=debug
#SBATCH --time=15:00
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8

srun /home/albuquer/plateformes/hello
