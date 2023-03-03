function tabuada() {
    let num = document.getElementById('num')
    let selct = document.getElementById('selct')
    if (num.value.length == 0) {
        window.alert('[ERRO] Insira um numero para obter a tabuada!')
    } else {
        let n = Number(num.value)
        selct.innerHTML = ''
        for(let c = 1; c <=10; c++) {
            let item = document.createElement('option')
            item.text = `${n} x ${c} = ${n*c}`
            item.value = `tab${c}`
            selct.appendChild(item)
        }
    }
}