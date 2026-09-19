import sys
from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt
p=Path(sys.argv[1] if len(sys.argv)>1 else 'results/equity.csv')
df=pd.read_csv(p);df['return']=df.equity.pct_change();df['peak']=df.equity.cummax();df['drawdown']=df.equity/df.peak-1
out=p.parent/'plots';out.mkdir(exist_ok=True)
fig,ax=plt.subplots(2,1,sharex=True);ax[0].plot(df.index,df.equity);ax[0].set_title('Backtest / Experimental Equity');ax[1].plot(df.index,df.drawdown);ax[1].set_title('Drawdown');fig.tight_layout();fig.savefig(out/'equity_drawdown.png',dpi=150)
print(df[['equity','return','drawdown']].describe())
