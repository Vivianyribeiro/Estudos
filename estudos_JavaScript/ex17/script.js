let num = document.querySelector('input#num')
let lista = document.querySelector('select#seletor')
let res = document.querySelector('article#res')
let valores = []

function isNumero(n){
    if (Number(n) >= 1 && Number(n)<= 100) {
        return true
    } else {
        return false
    }
}
function inLista(n, l){
    if(l.indexOf(Number(n)) != -1){ //menos 1 quando nao tem la no array
        return true
    } else {
        return false
    }
}

function adiciona(){
    if (isNumero(num.value) && !inLista(num.value, valores)) {
        valores.push(Number(num.value))
        let novofilho = document.createElement('option')
        novofilho.text = `inserido valor ${num.value}`
        lista.appendChild(novofilho)
        res.innerHTML = '' //se inseri outros apos finalizar uma vez limpa o res
    } else {
        window.alert('Valor inválido ou ja existente')
    }
    num.value = ''
    num.focus() // o cursor
}

function finalizar(n) {
    if (valores.length == 0) {
        window.alert('Insira os valores')
    } else {
        res.innerHTML = `Foram inseridos ${valores.length} itens no seletor`
        res.innerHTML += `<br>Os numeros inseridos foram:`
        for (let c = 0; c < valores.length; c++) {
        res.innerHTML += ` ${valores[c]} - `
        }
        let maior = valores[0]
        let menor = valores[0]
        let soma = 0
        let media = 0
        for(let pos in valores) {
            soma += valores[pos]
            if(valores[pos] > maior) {
                maior = valores[pos] 
            }
            if(valores[pos] < menor) {
                menor = valores[pos]
            }
        }
        media = soma / valores.length
        res.innerHTML += `<p>O maior valor e ${maior}</p>`
        res.innerHTML += `<p>O menor valor e ${menor}</p>`
        res.innerHTML += `<p>A soma dos valores inseridos é ${soma}.</p>`
        res.innerHTML += `<p>A media dos valores é ${media.toFixed(2)}.</p>`
    }
}