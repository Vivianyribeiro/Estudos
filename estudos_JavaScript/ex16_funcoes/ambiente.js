let num = [5,8,3,9,1]
num[5] = 6
num.push(7) //aqui coloca o numero no final do array, vc nao precisa saber qual indice é o final
num.sort() //coloca tudo em ordem crescente

console.log(`Nosso vetor é ${num}`)
console.log(`O vetor tem ${num.length} posiçoes`) //num.length //da o tamanho do vetor
console.log(`O primerio valor do vetor é ${num[0]}`)
for (let c = 0; c <  num.length; c++) {
    console.log(`Posição ${c} = ${num[c]}`)
}

for(let pos in num){
    console.log(`A posição ${pos} tem valor ${num[pos]}`)
}
let pos = num.indexOf(7)
if (pos == -1) {  //da -1 quando nao é encontrado o cara dentro do vetor, ARRAY
    console.log('O valor nao foi encontrado!')
} else {
    console.log(`O valor esta na posicao ${pos}`)
}