#! /bin/bash

#   @author      : SRvSaha
#   Filename     : string.sh
#   Timestamp    : 14:35 03-October-2016 (Monday)
#   Description  : Expt 5: Shell Scripting || OS Lab
#

echo "Enter a string : ";
read str;
echo "Length of the string entered is :" ${#str};
echo "Different way to calculate length is :" `expr length $str`; # This can also be done

words=( $str ); # Converting the string into an array.
echo "Word Count is :" ${#words[@]} ;# Counting the length of the array

printf "%s\n" "${words[@]}"; # Way to print an array of strings in One Line

count_vowel=0;
count_consonant=0;
for (( i = 0; i < ${#str}; i++ )); do
    ch=${str:$i:1}; # Sub-string of length 1 in str starting from $i
    case $ch in [aeiouAEIOU] )
        count_vowel=$(($count_vowel+1));;
    esac
done
echo "Number of Vowels : "$count_vowel;
count_consonant=$((${#str}-$count_vowel));
echo "Number of Consonants : "$count_consonant

echo "The the string you want to concatenate :"
read str1

space=" "
concatenated=$str$space$str1
echo "Concatenated String is:" $concatenated
echo "Alternative way for concatenation :"
echo "$str $str1" # Easy and efficient way of concatenation
echo "Another way for concatenating is :"
str+=" "$str1 # This is also an easy and efficient way. But it's inplace
echo $str

echo "Enter the first string: "
read string1
echo "Enter the second string: "
read string2

if [ "$string1" == "$string2" ]; then # MIND THE SPACES
    echo "Strings Are Equal"
else
    echo "Strings are Unequal"
fi
