package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("Bienvenue dans la calculatrice !")

	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Println("Entrez une opération (ou tapez 'exit' pour quitter) :")

		oper, _ := reader.ReadString('\n')
		oper = strings.TrimSpace(oper)

		if oper == "exit" {
			fmt.Println("Au revoir !")
			break
		}

		fmt.Println("Entrez le premier nombre :")

		num1Str, _ := reader.ReadString('\n')
		num1Str = strings.TrimSpace(num1Str)
		num1, err := strconv.ParseFloat(num1Str, 64)
		if err != nil {
			fmt.Println("Erreur : Entrée invalide pour le premier nombre.")
			continue
		}

		fmt.Println("Entrez le deuxième nombre :")

		num2Str, _ := reader.ReadString('\n')
		num2Str = strings.TrimSpace(num2Str)
		num2, err := strconv.ParseFloat(num2Str, 64)
		if err != nil {
			fmt.Println("Erreur : Entrée invalide pour le deuxième nombre.")
			continue
		}

		var result float64

		switch oper {
		case "+":
			result = num1 + num2
		case "-":
			result = num1 - num2
		case "*":
			result = num1 * num2
		case "/":
			if num2 != 0 {
				result = num1 / num2
			} else {
				fmt.Println("Erreur : Division par zéro.")
				continue
			}
		default:
			fmt.Println("Erreur : Opérateur non valide.")
			continue
		}

		fmt.Println("Le résultat est :", result)
	}
}
