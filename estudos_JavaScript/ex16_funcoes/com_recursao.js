//recursividade e quando uma funcao chama ela mesma
function fatorial(n) {
    if (n == 1) {
        return 1
    }else {
        return n * fatorial(n-1)
    }
}
console.log(fatorial(5))
let res = fatorial(5) // tu escolhe como tu que imprimir, com variavel ou sem
console.log(res)