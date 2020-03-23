. /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.14.06/x86_64-centos7-gcc48-opt/bin/thisroot.sh

if [[ ! -d data ]]; then
  git clone git@github.com:pcm-dpc/COVID-19.git $PWD/data
  python produce_dataset.py
else
  cd data
  git pull
  cd -
fi
