/*
  main/driver program for alpha signal tester.

  Example command lines:
  run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_BKFRT_DELL_inclFees_noVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-BASIC"

# Basic run:  ETF KFRT, DELL + SPY, 1 day.  Includes fees but not trading volume.
run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_SPY_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_noVolume_SPY.ticks

# Basic run:  ETF KFRT, DELL + SPY, 1 day.  Includes fees and trading volume.
run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_SPY_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_inclVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"  --useVolume true --printTicks true >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_inclVolume_SPY.ticks

# Basic run:  ETF KFRT, DELL + SPY, 1 day.  Includes fees and trading volume.  New version with lib3 code & neworder branch.
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home/mcheyney/tcost/DELL_SPY_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_inclVolume_SPY.20091230.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"  --useVolume true --printTicks true --nyse --arca --bats --isld >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_DELL_inclFees_inclVolume_SPY.20091230.ticks

# Basic run:  ETF KFRT, Tech stocks + SPY, 1 day.  Includes fees and trading volume.  New version with lib3 code & neworder branch. 
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_inclVolume_SPY.20091230.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"  --useVolume true --printTicks true --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_inclVolume_SPY.20091230.ticks

# ETF KFRT, Tech stocks + SPY, 1 day.  Includes fees and trading volume.  New version with lib3 code & neworder branch. 
# Run with new formulation for bid ask bounce error variance:
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_inclVolume_SPY.nmev.20091230.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"  --useVolume true --printTicks true --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_inclVolume_SPY.nmev.20091230.ticks

# LFM BARRA EXP MODEL KFRT, Industry factors only.  
# Tech stocks only, 1 day.  Includes fees and trading volume.  New version with lib3 code & neworder branch. 
# Run with new formulation for bid ask bounce error variance:
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/Tech_symbols.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_KFRT_ERM_LFMBARRA_INDONLY_Tech_inclFees_inclVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalFlavor "LFM-BARRA" --useVolume true --printTicks true --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --barraRiskFile "/apps/home-ny/mcheyney/study/USE3S0909.INDUSTRY_ONLY.RSK" >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_KFRT_ERM_LFMBARRA_INDONLY_Tech_inclFees_inclVolume.ticks

# PLSOB/ImbTracker signal.  
# Tech stocks only, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/Tech_symbols.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_IMB_Tech.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalFlavor "PLSOB" --printTicks true --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20090921/" --sim-trade-file "simconfig" >& /spare/local/mcheyney/ntradesys/tsim/20090921/20090921/AST_IMB_Tech.ticks

# Testing 3 signals at once:
# signalKFRTETF
# signalKFRTExpMBarra (industry only).
# signalPLSOB  
# DELL only, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_SPY_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_KFRTETF_PLSOB_KFRTEXPMBARRA_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalKFRTETF --signalKFRTExpMBarra --signalPLSOB --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20090921/" --sim-trade-file "simconfig" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" --barraRiskFile "/apps/home-ny/mcheyney/study/USE3S0909.INDUSTRY_ONLY.RSK" --exitOnClose --useVolume

# Testing 1 signal with new multi-tester functionality:
# KFRTETF
# PLSOB
# DELL only, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/study/symbol_files/ticker_SPY/DELL" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/per_symbol/DELL/20090921/AST_KFRTETF_PLSOB.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/per_symbol/DELL20090921/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --signalPLSOB --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/per_symbol/DELL/20090921/" --sim-trade-file "simconfig" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" --exitOnClose --useVolume

# Testing 2 signals with new multi-tester functionality:
# signalKFRTETF
# DELL only, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_SPY_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/ASTMULTI_KFRTETF_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalKFRTETF --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20090921/" --sim-trade-file "simconfig" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" --exitOnClose --useVolume --printTicks >& "/spare/local/mcheyney/ntradesys/tsim/20090921/ASTMULTI_KFRTETF_DELL.ticks.20100128"

# Testing 3 signals at once:
# signalKFRTETF
# signalKFRTExpMBarra (industry only).
# signalPLSOB  
# Tech stocks only, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/ASTMULTI_KFRTETF_PLSOB_KFRTEXPMBARRA_Tech.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalKFRTETF --signalKFRTExpMBarra --signalPLSOB --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20090921/" --sim-trade-file "simconfig" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" --barraRiskFile "/apps/home-ny/mcheyney/study/USE3S0909.INDUSTRY_ONLY.RSK" --exitOnClose --useVolume

# Testing 3 signals at once:
# signalKFRTETF
# signalKFRTExpMBarra (industry only).
# signalPLSOB  
# R1 members, 1 day.  
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/R1_symbols_plus_SPY.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/ASTMULTI_KFRTETF_PLSOB_KFRTEXPMBARRA_R1.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalKFRTETF --signalKFRTExpMBarra --signalPLSOB --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20090921/" --sim-trade-file "simconfig" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt" --barraRiskFile "/apps/home-ny/mcheyney/study/USE3S0909.INDUSTRY_ONLY.RSK" --exitOnClose --useVolume

# PLSOB/ImbTracker signal.  
# DELL only, Nov 2009 day.  
run --start-date 20091102 --end-date 20091201 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091101/AST_IMB_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091101/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalFlavor "PLSOB" --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091101/" --sim-trade-file "simconfig" --printTicks true

# SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, Nov 2009 day.  
run --start-date 20091102 --end-date 20091102 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091101/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.log.20100329" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091101/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091101/" --sim-trade-file "simconfig"

# SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, Nov 2009 day.  
# Sample every 1 second.
run --start-date 20091102 --end-date 20091103 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091101/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.1sec.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091101/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091101/" --sim-trade-file "simconfig" --sample-freq 1000

run --start-date 20091103 --end-date 20091104 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091103/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.1sec.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091103/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091103/" --sim-trade-file "simconfig" --sample-freq 1000

run --start-date 20100415 --end-date 20100416 --symbol-file "/apps/home-ny/mcheyney/tcost/RSG_SPY_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20100415/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_RSG.1sec.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20100415/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20100415/" --sim-trade-file "simconfig" --sample-freq 1000

run --start-date 20100415 --end-date 20100416 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_RSG_SPY_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20100415/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL_RSG_SPY.1sec.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20100415/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20100415/" --sim-trade-file "simconfig" --sample-freq 1000

# SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, Nov 2009 day.  
# Sample every 10 seconds.
run --start-date 20091102 --end-date 20091102 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091101/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.10sec.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091101/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091101/" --sim-trade-file "simconfig" --sample-freq 10000

# SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# AWK only, Nov 2009 day.  
run --start-date 20091102 --end-date 20091103 --symbol-file "/apps/home-ny/mcheyney/tcost/AWK_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091102/AST_ShsTd_ShsTdBuy_ShsTdSell_Vol_AWK.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091102/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091102/" --sim-trade-file "simconfig"

# KFRTETF SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, Nov 2009 day. 
# With printTicks enabled for KFRTETF signal. 
run --start-date 20091102 --end-date 20091103 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091102/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091102/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --printTicks --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091102/" --sim-trade-file "simconfig" >& /spare/local/mcheyney/ntradesys/tsim/20091102/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.out

# KFRTETF SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, Nov 2009 day. 
# With printTicks NOT enabled for KFRTETF signal. 
run --start-date 20091102 --end-date 20091103 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091102/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091102/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091102/" --sim-trade-file "simconfig"

run --start-date 20091103 --end-date 20091104 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091103/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091103/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091103/" --sim-trade-file "simconfig"

# KFRTETF SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# DELL only, March 2010 day. 
# With printTicks enabled for KFRTETF signal. 
run --start-date 20100330 --end-date 20100331 --symbol-file "/apps/home-ny/mcheyney/tcost/DELL_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20100330/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20100330/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --printTicks --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20100330/" --sim-trade-file "simconfig" >& /spare/local/mcheyney/ntradesys/tsim/20100330/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_DELL.out

# KFRTETF SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# AWK only, Nov 2009 day. 
# With printTicks enabled for KFRTETF signal. 
run --start-date 20091102 --end-date 20091102 --symbol-file "/apps/home-ny/mcheyney/tcost/AWK_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091101/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_AWK.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091101/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --printTicks --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20091101/" --sim-trade-file "simconfig" >& /spare/local/mcheyney/ntradesys/tsim/20091101/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_AWK.out

# KFRTETF SharesTraded, SharesTradedTLBuy, SharesTradedTLSell, Volatility signal(s).  
# AWK only, March 2010 day. 
# With printTicks enabled for KFRTETF signal. 
run --start-date 20100330 --end-date 20100331 --symbol-file "/apps/home-ny/mcheyney/tcost/AWK_population_set.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20100330/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_AWK.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20100330/"  --file-table.path "/apps/home-ny/mcheyney/new_code/gt-params" --signalKFRTETF --printTicks --signalSharesTraded --signalSharesTradedBuyerTL --signalSharesTradedSellerTL --signalVolatility --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS --trade-type sim --sim-output-dir "/spare/local/mcheyney/ntradesys/tsim/20100330/" --sim-trade-file "simconfig" >& /spare/local/mcheyney/ntradesys/tsim/20100330/AST_KFRTETF_ShsTd_ShsTdBuy_ShsTdSell_Vol_AWK.out


# ETF KFRT, R1mem + SPY, 1 day.  Includes fees and trading volume.  New version with lib3 code & neworder branch. 
# Run with new formulation for bid ask bounce error variance:
# Paths set up for use with Waltham machine cluster.
run --start-date 20090921 --end-date 20090922 --symbol-file "/apps/home-ny/mcheyney/tcost/R1_symbols_plus_SPY.txt" --timer-freq 1000 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_R1_inclFees_inclVolume_SPY.nmev.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home-ny/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home-ny/mcheyney/study/R1_SPY_betas.txt"  --useVolume true --printTicks true --data-on ISLD --data-on ARCA --data-on NYSE --data-on BATS >& /spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_R1_inclFees_inclVolume_SPY.nmev.ticks

  run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.20091110.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

## Divide signal vs sqrt(est var).
run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.20091110.div.by.vol.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

## Use a longer-term IBVolTracker:  Sample every 1 seconds, with 3600 samples (1 hour vol), instead of sample every second, with 360 samples (5 minute vol).
run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.20091110.vol.1000.3600.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

## Use a longer-term IBVolTracker:  Sample every 5 seconds, with 720 samples (1 hour vol), instead of sample every second, with 360 samples (5 minute vol).
run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.20091110.vol.5000.720.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

  run --start-date 20090922 --end-date 20090923 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090922/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090922/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

  run --start-date 20090923 --end-date 20090924 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090923/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090923/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

run --start-date 20090924 --end-date 20090925 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090924/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090924/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

run --start-date 20090925 --end-date 20090926 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_SPY.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090925/AST_ETFKFRT_Tech_inclFees_noVolume_SPY.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090925/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_SPY_betas.txt"

run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_XLK.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_ETFKFRT_Tech_inclFees_noVolume_XLK.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas.txt"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_BKFRT_DELL_inclFees_noVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090706/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF"

run --start-date 20090921 --end-date 20090922 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/Tech_symbols_plus_XLK.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090921/AST_BKFRT_Tech_inclFees_noVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090921/"  --file-table.path "/apps/home/mcheyney/study" --signalFlavor "KFRT-ETF"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/XLK_DELL_population_set.txt" --signalFlavor "KFRT-ETF" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_ETFKFRT_DELL_inclFees_noVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090706/"  --file-table.path "/apps/home/mcheyney/study" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas.txt"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/XLK_DELL_population_set.txt" --useVolume true --signalFlavor "KFRT-ETF" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_ETFKFRT_DELL_inclFees_inclVolume.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090706/"  --file-table.path "/apps/home/mcheyney/study" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas.txt"

  run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_BKFRT_DELL_inclFees_inclVolume.log" --useVolume true

  run --start-date 20090317 --end-date 20090318 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_population_set.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090317/AST_BKFRT_DELL.log"

  run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_BKFRT_R1.log"

  run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_BKFRT_R1_inclFees_noVolume.log"

  run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols_plus_ETFs.txt" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_ETFKFRT_R1_inclFees_noVolume.log"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols_plus_ETFs.txt" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas_all_1.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_ETFKFRT_R1_betaOne_inclFees_noVolume.log"

  run --start-date 20091102 --end-date 20091103 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols_plus_ETFs.txt" --signalFlavor "KFRT-ETF" --etfBetaFile "/apps/home/mcheyney/study/R1_ETF_betas.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091102/AST_ETFKFRT_R1_inclFees_noVolume.log"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_MSFT_symbols.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_BKFRT_DELL_MSFT_inclFees_noVolume.log"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/DELL_population_set.txt" --signalFlavor "PLSOB" --plsobKFile "/apps/home/mcheyney/study/PLSOB_K_R1Mem.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_PLSOB_DELL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090706/"  --file-table.path "/apps/home/mcheyney/study"

run --start-date 20090706 --end-date 20090707 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/R1_symbols_plus_ETFs.txt" --signalFlavor "PLSOB" --plsobKFile "/apps/home/mcheyney/study/PLSOB_K_R1Mem.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20090706/AST_PLSOB_R1mem.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20090706/"  --file-table.path "/apps/home/mcheyney/study"

run --start-date 20091002 --end-date 20091003 --simtrade  --simtrade-log "mcheyney/ntradesys/tsim/SMMtsim.txt" --symbol-file "/apps/home/mcheyney/tcost/AAPL_symbols.txt" --signalFlavor "PLSOB" --plsobKFile "/apps/home/mcheyney/study/PLSOB_K_R1Mem_Amrit.txt" --wake-freq 2  --timer-freq 1000 --default-max-exposure 25000 --default-max-orders 5 --default-max-position 10000 --max-submkt-depth 10 --useAsynchLogger true --asynchLogFile "/spare/local/mcheyney/ntradesys/tsim/20091002/AST_PLSOB_AAPL.log" --debug-stream.path "/spare/local/mcheyney/ntradesys/tsim/20091002/"  --file-table.path "/apps/home/mcheyney/study" >& /spare/local/mcheyney/ntradesys/tsim/20091002/AST_PLSOB_AAPL.std
*/

#include "DataManager.h"

#include <cl-util/factory.h>
#include <cl-util/debug_stream.h>
#include <cl-util/table.h>
using namespace clite::util;

#include "HFUtils.h"

#include "ASTMain.h"
#include "AlphaSignalTester.h"
#include "ExplanatoryModel.h"
#include "BarraUtils.h"

// Include files for specfic signal being tested.
#include "KFRTSignal.h"
#include "OpenTracker.h"
#include "VolatilityTracker.h"
#include "IBVolatilityTracker.h"
#include "ImbTracker.h"
#include "MarketImpactResearch.h"
#include "IntervalVolumeTracker.h"

#include <tael/Log.h>
#include <tael/FdLogger.h>

using namespace trc;
 
ASTConfigHelper::ASTConfigHelper() {
  setDefaultValues();
  setConfigOptions();
}

ASTConfigHelper::~ASTConfigHelper() {

}

void ASTConfigHelper::setDefaultValues() {
  useAsynchLogger = true;
  taelLogFile = "/spare/local/ase/ntradesys/tsim/AST.log";
  listenISLD = listenBATS = listenARCA = listenNYSE = true;
  exchangeFile = "/apps/exec/param-files/exchanges.20090828";
  useVolume = false;
  printTicks = false;
  exitOnClose = false;
  signalKFRTBasic = false;
  signalKFRTETF = false;
  signalKFRTExpMBarra = false;
  signalPLSOB = false;
  signalSharesTraded = false;
  signalSharesTradedBuyerTL = false;
  signalSharesTradedSellerTL = false;
  signalVolatility = false;
  etfBetaFile = "/apps/home/mcheyney/study/R1_ETF_betas.txt";
  plsobKFile = "/apps/home/mcheyney/study/PLSOB_K_R1Mem.txt";
  barraRiskFile = "/apps/compustat/barra/data/RSK/USE3S0909.RSK";
  barraIndexWeightsFile = "/apps/home-ny/mcheyney/study/R1_barra_index_weights_t.txt";
  checkBarraWeights = false;
  printBarraMatrices = true;  
  timerFreq = 1000;
  sampleFreq = 60000;
}

void ASTConfigHelper::setConfigOptions() {
  defOption("exchangeFile", &exchangeFile, "File holding ticker --> exchange mapping");
  defOption("listenISLD", &listenISLD, "Listen to ISLD data (default true)", true);
  defOption("listenBATS", &listenBATS, "Listen to BATS data (default true)", true);
  defOption("listenARCA", &listenARCA, "Listen to ARCA data (default true)", true);
  defOption("listenNYSE", &listenNYSE, "Listen to NYSE data (default true)", true);
  defOption("taelLogFile", &taelLogFile, "File to which TAEL logger should send output");
  defOption("useVolume", &useVolume, "Whether KFRT signal should attempt to use volume info in signal");
  defOption("printTicks", &printTicks, "Whether KFRT signal should print info about state update on every tick");
  defOption("exitOnClose", &exitOnClose, "Whether tester should exit when it sees market-close message");
  defOption("signalKFRTBasic", &signalKFRTBasic, "Include KFRT-Basic signal");
  defOption("signalKFRTETF", &signalKFRTETF, "Include KFRT-ETF signal");
  defOption("signalKFRTExpMBarra", &signalKFRTExpMBarra, "Include KFRT-EXPM-BARRA signal");
  defOption("signalPLSOB", &signalPLSOB, "Include PLSOB signal");
  defOption("signalSharesTraded", &signalSharesTraded, "Include SharesTraded signal");
  defOption("signalSharesTradedBuyerTL", &signalSharesTradedBuyerTL, "Include SharesTraded signal");
  defOption("signalSharesTradedSellerTL", &signalSharesTradedSellerTL, "Include SharesTraded signal");
  defOption("signalVolatility", &signalVolatility, "Include Volaltility estimate signal");
  defOption("etfBetaFile", &etfBetaFile, "File holding stock -> {ETF, Beta} mappings");
  defOption("plsobKFile", &plsobKFile, "File holding stock -> PLSOB model params mapping");
  defOption("barraRiskFile", &barraRiskFile, "Barra .RSK file containing stock factor betas");
  defOption("barraIndexWeightsFile", &barraIndexWeightsFile, "File containing weights for synthetic indeces used to construct risk factor analogues");
  defOption("checkBarraWeights", &checkBarraWeights, "Check whether the BARRA index weights sum to expected value (true)");
  defOption("printBarraMatrices", &printBarraMatrices, "Print barra factorWeights and factorBetas matrices (for debugging)");
  defOption("timer-freq", &timerFreq, "Global timer-frequency");
  defOption("sample-freq", &sampleFreq, "AlphaSignalObservation sampling frequency");
}


int main(int argc, char **argv) {

  bool help;
  if (argc < 2) { cerr << "Need at least one argument!" << endl; return 1; }
  bool live = strncmp(argv[1], "--live", 6) == 0;
  if (live == true) {
    argc = argc - 1;
    argv = argv + 1;
  }
  CmdLineFileConfig cfg (argc, argv, "config,C");
  cfg.defSwitch("help,h", &help, "print this help.");

  /*
    Get new Live/Hist DataManager from DataManager factory.
  */
  factory<DataManager>::pointer dm(factory<DataManager>::get(only::one));

  /*
    Parse command line options into LSTZTraderConfigHelper structure.
  */
  ASTConfigHelper cfgHelper;
  cfg.add(*dm);
  cfg.add(cfgHelper);

  cfg.add(*(file_table_config::get_config()));
  cfg.add(*(debug_stream_config::get_config()));

  if (!cfg.configure()) { cerr << cfg << endl; return 1; }

  if (help) { cerr << cfg << endl; return 1; }

  /*
    Set up debug print / output file, plus logging destination.
  */     
  tael::Logger ddebug(tael::Logger(*(new tael::LoggerConfiguration((size_t) MAX_BINARY_BUFFER_FILE_SIZE))));  // Debugging info, to stdout/stderr.
  tael::Logger dsignal(tael::Logger(*(new tael::LoggerConfiguration((size_t) MAX_BINARY_BUFFER_FILE_SIZE))));    // Signal testing, to aysnch log file.

  int fd = open(cfgHelper.taelLogFile.c_str(), O_RDWR | O_CREAT | O_APPEND, 0640);
  if (fd == -1) {
      cerr << "Unable to open server log " << cfgHelper.taelLogFile << ", dying." << endl;
      return 1;
  }
  else {
	  boost::shared_ptr<tael::LoggerDestination> fld = new tael::FdLogger(fd);
      HFUtils::setupLogger(&dsignal, fld.get());
  }

  /*
    Lib2 version of code had calls here for turnining on/off up data sources.  
    In Lib3/neworder version of code, enabling/disabling various data sources
      is done automagically, via config options.    
  */

  if(!dm->initialize()) {
    std::cerr << "Unable to initialize DataManager, aborting program" << std::endl;
    return 2;
  }

  /*
    Signal specifific stuff:
    VolTracker configuration is fairly important for BasicKFRTSignal to work as expected....
  */
  // Imbalance signal.  Note:  Should be explicitly placed in factory system.
  factory<ImbTracker>::pointer imbSignal = factory<ImbTracker>::get(only::one);

  // Basic KFRT signal.
  IBVolatilityTracker volt(1000, 3600, 300, imbSignal.get());
  SpdTracker spdt(50, 60, 1000);  
  factory<BasicKFRTSignal>::pointer kfrtSignal = factory<BasicKFRTSignal>::get(only::one);
  kfrtSignal->setPrintTicks(cfgHelper.printTicks);

  AlphaSignal *signal;

  // Experimental - for testing AverageTradingImpactModel
  AverageTradingImpactModel _atim;
  // Experimental - for testing VolumeImbalanceTradingImpactModel.
  VolumeImbalanceTradingImpactModel _tim(imbSignal.get());  
  // Experimental - for testing BookTradingImpactModel.
  BookTradingImpactModel _btim;  
  // Experimental - for testing ImbTradingImpactModel.
  ImbTradingImpactModel _itim(imbSignal.get());

  vector<AlphaSignal*> signals;
 
  
  if (cfgHelper.signalKFRTBasic == true) {
    //signal = new BasicKFRTSignal(&volt, &spdt, cfgHelper.useVolume, cfgHelper.printTicks);
    //signals.push_back(signal);
    signals.push_back(kfrtSignal.get());
  } 
  if (cfgHelper.signalKFRTETF == true) {
    factory<ETFKFRTSignal>::pointer etfKFRTSignal = factory<ETFKFRTSignal>::get(only::one);
    etfKFRTSignal->setPrintTicks(cfgHelper.printTicks);
    signals.push_back(etfKFRTSignal.get());
  } 
  if (cfgHelper.signalPLSOB == true) {
    //BookElemTrackerHW _bet(dm, ddebug, 60000);
    //PartialOrderBookTracker _pobt(dm, &_bet, dm->cidsize(), 10);
    //LiteOrderBookTracker _lobt(dm);
    //signal = new PLSOBSignal(dm, &_pobt, &_lobt, cfgHelper.plsobKFile);
    signals.push_back(imbSignal.get());
  } 
  if (cfgHelper.signalKFRTExpMBarra == true) {
    bmatrixd factorWeights;
    bmatrixd factorBetas;
    ExplanatoryReturnModel *erm;

    // KFRT with ExplanatoryModel, using BARRA linear factor model.
    // Should be able to use entire BARRRA factor set, or industry factors only,
    //   depending on the BARRA .RSK file specified.
    if (!BarraUtils::populateStockBetasFile(dm.get(), cfgHelper.barraRiskFile, factorBetas, cfgHelper.checkBarraWeights)) {
      cerr << "Unable to populate BARRA factorBetas matrix " << endl; 
      return 1;      
    }
    if (!BarraUtils::populateIndexWeightsFile(dm.get(), cfgHelper.barraIndexWeightsFile, factorWeights, cfgHelper.checkBarraWeights)) {
      cerr << "Unable to populate BARRA factorWeights matrix " << endl; 
      return 1;      
    }    
    if (cfgHelper.printBarraMatrices) {
      string fw("factorWeights");
      string fb("factorBetas");
      BarraUtils::printFactorMatrix(dm.get(), fb, factorBetas);
      BarraUtils::printFactorMatrix(dm.get(), fw, factorWeights);
    }
    erm = new ERMLinearMultiFactor(NULL, factorWeights, factorBetas);
    ExplanatoryModelKFRTSignal *expmS = new ExplanatoryModelKFRTSignal(erm);
    factory<ExplanatoryModelKFRTSignal>::insert( only::one, expmS );
    expmS->setPrintTicks(cfgHelper.printTicks);
    signals.push_back(expmS);
  }  

  if (cfgHelper.signalSharesTraded == true) {
    signal = new SharesTradedSignal(cfgHelper.sampleFreq);
    signals.push_back(signal);
  } 
  if (cfgHelper.signalSharesTradedBuyerTL == true) {
    signal = new SharesTradedBuyerTLSignal(cfgHelper.sampleFreq);
    signals.push_back(signal);    
  }
  if (cfgHelper.signalSharesTradedSellerTL == true) {
    signal = new SharesTradedSellerTLSignal(cfgHelper.sampleFreq);
    signals.push_back(signal);    
  }  
  if (cfgHelper.signalVolatility == true) {
    signal = new VolatilitySignal(&volt);
    signals.push_back(signal);    
  }    
 
  // Make tester - configured to sample every minute.
  // timer-update frequency should be set to <= this.
  AlphaSignalTester tester(signals, dsignal, 0, cfgHelper.sampleFreq, cfgHelper.exitOnClose);
  
  //
  // Generate a global timer to driver things that expect regular admin updates.
  //
  dm->addTimer(Timer(TimeVal(0,cfgHelper.timerFreq * 1000),TimeVal(0,0)));

  // All taken care of in constructors....
  //dm->addListener(&opent);
  //dm->addListener(&volt);
  //dm->addListener(&tester);
  
  // Hand off main-thread control to DataManager event loop.
  // Should cause code to start receiving calls to PortGenDriver s
  //   update and wakeup functions.
  dm->run();
  
  //delete dm;
  delete signal;
}
