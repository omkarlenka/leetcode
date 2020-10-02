package main

import (
	"fmt"
	"strings"
)

var ones = make(map[int]string)
var tens = make(map[int]string)
var tripletNumber = make(map[int]string)

func initMaps() {
	for i := 1; i < 20; i++ {
		switch i {
		case 1:
			ones[i] = "One"
		case 2:
			ones[i] = "Two"
			tens[i] = "Twenty"
		case 3:
			ones[i] = "Three"
			tens[i] = "Thirty"
		case 4:
			ones[i] = "Four"
			tens[i] = "Forty"
		case 5:
			ones[i] = "Five"
			tens[i] = "Fifty"
		case 6:
			ones[i] = "Six"
			tens[i] = "Sixty"
		case 7:
			ones[i] = "Seven"
			tens[i] = "Seventy"
		case 8:
			ones[i] = "Eight"
			tens[i] = "Eighty"
		case 9:
			ones[i] = "Nine"
			tens[i] = "Ninety"
		case 10:
			tens[i] = "Ten"
		case 11:
			tens[i] = "Eleven"
		case 12:
			tens[i] = "Twelve"
		case 13:
			tens[i] = "Thirteen"
		case 14:
			tens[i] = "Fourteen"
		case 15:
			tens[i] = "Fifteen"
		case 16:
			tens[i] = "Sixteen"
		case 17:
			tens[i] = "Seventeen"
		case 18:
			tens[i] = "Eighteen"
		case 19:
			tens[i] = "Nineteen"
		}
	}

	tripletNumber[2] = "Thousand"
	tripletNumber[3] = "Million"
	tripletNumber[4] = "Billion"
	tripletNumber[5] = "Trillion"
}

func getTripletRes(digit1 int, digit2 int, digit3 int) string {
	var res string

	if digit1 > 0 {
		res = ones[digit1] + " Hundred"
	}
	if digit2 > 0 {
		if digit2 == 1 {
			res = strings.Trim(res, " ") + " " + tens[digit2*10+digit3]
		} else {
			res = strings.Trim(res, " ") + " " + tens[digit2] + " " + ones[digit3]
		}
	} else {
		res = strings.Trim(res, " ") + " " + ones[digit3]
	}
	res = strings.Trim(res, " ")
	return res
}

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}
	var res string
	var currentNumDigits, triplet int
	var digit1, digit2, digit3 int
	initMaps()
	for num > 0 {
		currentNumDigits++

		if currentNumDigits == 1 {
			digit3 = num % 10
			triplet++
		} else if currentNumDigits == 2 {
			digit2 = num % 10
		} else if currentNumDigits == 3 {
			digit1 = num % 10
			if (triplet > 1) && (digit1 > 0 || digit2 > 0 || digit3 > 0) {
				res = getTripletRes(digit1, digit2, digit3) + " " + tripletNumber[triplet] + " " + res
			} else {
				res = getTripletRes(digit1, digit2, digit3) + " " + res
			}
			digit1 = 0
			digit2 = 0
			digit3 = 0
			currentNumDigits = 0
			res = strings.Trim(res, " ")
		}
		num /= 10
	}
	if digit1 > 0 || digit2 > 0 || digit3 > 0 {
		if triplet > 1 {
			res = getTripletRes(digit1, digit2, digit3) + " " + tripletNumber[triplet] + " " + res
		} else {
			res = getTripletRes(digit1, digit2, digit3) + " " + res
		}
	}
	res = strings.Trim(res, " ")
	return res
}

func main() {
	var number int
	number = 101
	fmt.Println(numberToWords(number))
}
