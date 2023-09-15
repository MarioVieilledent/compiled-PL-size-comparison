use std::io;

fn main() {
    println!("Bienvenue dans la calculatrice !");

    loop {
        println!("Entrez une opération (ou tapez 'exit' pour quitter) :");

        let mut oper = String::new();
        io::stdin()
            .read_line(&mut oper)
            .expect("Erreur lors de la lecture de l'opération.");

        let oper = oper.trim();

        if oper == "exit" {
            println!("Au revoir !");
            break;
        }

        println!("Entrez le premier nombre :");

        let mut num1 = String::new();
        io::stdin()
            .read_line(&mut num1)
            .expect("Erreur lors de la lecture du premier nombre.");

        let num1: f64 = match num1.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Erreur : Entrée invalide pour le premier nombre.");
                continue;
            }
        };

        println!("Entrez le deuxième nombre :");

        let mut num2 = String::new();
        io::stdin()
            .read_line(&mut num2)
            .expect("Erreur lors de la lecture du deuxième nombre.");

        let num2: f64 = match num2.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Erreur : Entrée invalide pour le deuxième nombre.");
                continue;
            }
        };

        let result = match oper {
            "+" => num1 + num2,
            "-" => num1 - num2,
            "*" => num1 * num2,
            "/" => {
                if num2 != 0.0 {
                    num1 / num2
                } else {
                    println!("Erreur : Division par zéro.");
                    continue;
                }
            }
            _ => {
                println!("Erreur : Opérateur non valide.");
                continue;
            }
        };

        println!("Le résultat est : {}", result);
    }
}