#!/usr/bin/env python
from ROOT import TFile, TTree
import pandas as pd
import glob

all_files = glob.glob("data/dati-andamento-nazionale/dpc-covid19-ita-andamento-nazionale-2020*.csv")

li = []

for filename in all_files:
    df = pd.read_csv(filename, index_col=None, header=0)
    li.append(df)

frame = pd.concat(li, axis=0, ignore_index=True)

frame["data"] = pd.to_datetime(frame["data"]).astype(int) / 10**9

frame["data"] = frame["data"].astype(int)

frame = frame.reset_index()

frame.to_csv('dataset.csv', header=False, sep=',')
