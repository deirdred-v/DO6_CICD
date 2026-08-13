echo grep 'text' txt2.txt
grep 'text' txt2.txt >> temp1.txt
./s21_grep 'text' txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -e 'an' -e 'text' txt1.txt txt2.txt
grep -e 'an' -e 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -e 'an' -e 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -v 'text' txt1.txt txt2.txt
grep -v 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -v 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -c 'text' txt1.txt txt2.txt
grep -c 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -c 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -l 'text' txt1.txt txt2.txt
grep -l 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -l 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -n 'text' txt1.txt txt2.txt
grep -n 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -n 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep -i 'text' txt1.txt txt2.txt
grep -i 'text' txt1.txt txt2.txt >> temp1.txt
./s21_grep -i 'text' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep 't.xt' txt1.txt txt2.txt
grep 't.xt' txt1.txt txt2.txt >> temp1.txt
./s21_grep 't.xt' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep 't*' txt1.txt txt2.txt
grep 't*' txt1.txt txt2.txt >> temp1.txt
./s21_grep 't*' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep '^t' txt1.txt txt2.txt
grep '^t' txt1.txt txt2.txt >> temp1.txt
./s21_grep '^t' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------

echo grep '$t' txt1.txt txt2.txt
grep '$t' txt1.txt txt2.txt >> temp1.txt
./s21_grep '$t' txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: SUCCESS
else
    echo Test: FAILED
fi
rm temp*
echo -------------------------