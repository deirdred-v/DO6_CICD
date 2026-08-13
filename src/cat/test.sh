echo cat txt1.txt txt2.txt
cat txt1.txt txt2.txt >> temp1.txt
./s21_cat txt1.txt txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*
echo -------------------------

echo cat -b txt2.txt txt1.txt
cat -b txt2.txt txt1.txt >> temp1.txt
./s21_cat -b txt2.txt txt1.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*
echo -------------------------

echo cat -e txt2.txt
cat -e txt2.txt >> temp1.txt
./s21_cat -e txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*
echo -------------------------

echo cat -n txt2.txt
cat -n txt2.txt >> temp1.txt
./s21_cat -n txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*
echo -------------------------

echo cat -s txt2.txt
cat -s txt2.txt >> temp1.txt
./s21_cat -s txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*
echo -------------------------

echo cat -t txt2.txt
cat -t txt2.txt >> temp1.txt
./s21_cat -t txt2.txt >> temp2.txt
df=`diff temp1.txt temp2.txt`
if [ "$df" == "" ]; then 
    echo Test: success
else
    echo Test: faild
fi
rm temp*