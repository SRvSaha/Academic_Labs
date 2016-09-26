#! /bin/bash

# author : SRvSaha
# Description : Menu Driven Calcuator in Bash

echo "Please enter number 1 :"
read num1
echo "Please enter number 2 :"
read num2

echo "Enter your choice : 1. Add 2. Sub 3. Mul 4. Div"
read choice

case $choice in 
	1) ans=`expr $num1 + $num2 `; echo $ans;; # Whitespace in important for expr
	2) ans=`expr $num1 - $num2 `; echo $ans;;
	3) ans=`expr $num1 \\* $num2 `; echo $ans;; # * is a special charater so use \\ preceding * for multiplication
	4) ans=`expr $num1 / $num2 `; echo $ans;;
esac
