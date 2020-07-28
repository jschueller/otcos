#!/bin/sh

set -x -e

uid=$1
gid=$2


cd /tmp && curl -fSsLO https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh && cd ..
bash /tmp/Miniconda3-latest-Linux-x86_64.sh -b -p $HOME/miniconda
export PATH="$HOME/miniconda/bin:$PATH"
conda config --add channels conda-forge
conda install -y conda-build git

conda build /io/conda/recipe

# copy to host with same permission
if test -n "${uid}" -a -n "${gid}"
then
  sudo cp $HOME/miniconda/conda-bld/linux-64/otcos*.bz2 /io
  sudo chown ${uid}:${gid} /io/otcos*.bz2
fi
