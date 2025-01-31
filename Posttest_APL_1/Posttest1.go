package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

func login(username, password string) bool {
	return username == "Muhammad Ghazali" && password == "41"
}

func viewLogin() {
	var username, password string
	gagal := 0
	fmt.Println("Duid Converter")
	fmt.Println("-----------------")
	for gagal < 3 {
		fmt.Print("Masukkan Username: ")
		username, _ = reader.ReadString('\n')
		username = username[:len(username)-1]

		fmt.Print("Masukkan Password: ")
		password, _ = reader.ReadString('\n')
		password = password[:len(password)-1]

		if login(username, password) {
			fmt.Printf("Selamat datang %s\n", username)
			mainMenu()
		} else {
			gagal++
			fmt.Printf("Login gagal, %d Kesempatan lagi\n", 3-gagal)
		}
	}
	fmt.Println("Kesempatan habis program berakhir")
	return
}

func viewConvertCurrency() {
	var value float32
	var option int

	var fromCurrency, toCurrency string

	fmt.Print("Masukkan jumlah uang: ")
	fmt.Scanln(&value)

	fmt.Println("Mata uang asal")
	fmt.Println(`1. IDR
2. USD
3. EUR
4. JPY`)
	fmt.Scan(&option)
	if option == 1 {
		fromCurrency = "IDR"
	} else if option == 2 {
		fromCurrency = "USD"
	} else if option == 3 {
		fromCurrency = "EUR"
	} else if option == 4 {
		fromCurrency = "JPY"
	} else {
		fromCurrency = "Invalid"
	}

	fmt.Println("Mata uang tujuan")
	fmt.Println(`1. IDR
2. USD
3. EUR
4. JPY`)

	fmt.Scan(&option)
	if option == 1 {
		toCurrency = "IDR"
	} else if option == 2 {
		toCurrency = "USD"
	} else if option == 3 {
		toCurrency = "EUR"
	} else if option == 4 {
		toCurrency = "JPY"
	} else {
		toCurrency = "Invalid"
	}

	result, err := convert(value, fromCurrency, toCurrency)
	if err != nil {
		fmt.Println("Error", err)
		viewConvertCurrency()
	}
	fmt.Printf("%.2f %s = %2.f %s\n", value, fromCurrency, result, toCurrency)
	mainMenu()
}

func mainMenu() {
	var option int
	fmt.Println(`1. Konversi Mata Uang
2. Keluar `)
	fmt.Print("Pilihan: ")
	fmt.Scan(&option)
	if option == 1 {
		viewConvertCurrency()
	} else if option == 2 {
		os.Exit(0)
	} else {
		fmt.Println("Pilihan tidak valid")
		mainMenu()
	}
}

var exchangeRates = map[string]float32{
	// jadikan usd jadi patokan
	"USD": 1.00,
	"IDR": 15600.0,
	"EUR": 0.92,
	"JPY": 145.00,
}

func convert(value float32, fromCurrency, toCurrency string) (float32, error) {
	fromRate, ok1 := exchangeRates[fromCurrency]
	toRate, ok2 := exchangeRates[toCurrency]

	if !ok1 || !ok2 {
		return 0, errors.New("Mata uang tidak valid")
	}
	valueInUSD := value / fromRate
	valueConverted := valueInUSD * toRate

	return valueConverted, nil
}

func main() {
	viewLogin()
}
