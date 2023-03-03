let v = function(x) {
    return x*2
}
console.log(v(5))

function soma(n1=0, n2 = 0) {
    return n1 + n2
}

console.log(soma(7)) // no caso se eu passar apenas um parametro, vai considerar que o valor a se smoar co o n2 é 0

function fatorial(n) {
    let fat = 1
    for (let c = n; c > 0; c --) {
        fat *= c
    }
    return fat
}
let fatoriando = fatorial(5)
console.log(fatoriando)