#!/bin/env bash

#SBATCH --partition=gpu
#SBATCH --time=01:00:00
#SBATCH --gres=gpu:4
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=12

module load cuda

srun /home/albuquer/plateformes/plateformes_OpenCL

