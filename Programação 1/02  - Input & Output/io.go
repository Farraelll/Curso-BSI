package main

import "fmt"

func main() {
    var name string
    fmt.Print()
    fmt.Scanln(&name)

    fmt.Println("Olá, " + name)
}