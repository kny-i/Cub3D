#ok case
make -C ../src aok ||
make -C ../src bok ||
make -C ../src cok ||
make -C ../src dok ||
make -C ../src eok ||
make -C ../src fok ||

#ko case
make -C ../src ako ||
make -C ../src bko ||
make -C ../src cko ||
make -C ../src dko ||
make -C ../src eko ||
make -C ../src fko ||
make -C ../src gko ||
make -C ../src hko ||
make -C ../src iko
