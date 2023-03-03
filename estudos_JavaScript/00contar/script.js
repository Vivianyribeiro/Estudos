function contar() {
    var inicio = document.getElementById('txt1')
    var fim = document.getElementById('txt2')
    var passo = document.getElementById('txtpass')
    var res = document.getElementById('res')

    if (inicio.value.length == 0 || fim.value.length == 0 || passo.value.length == 0 ) {
        window.alert('[Erro] Digite os dados que faltam para proseguir!')
        res.innerHTML = 'Impossivel Contar'
    } else {
        res.innerHTML = 'Contando: '
        let i = Number(inicio.value)
        let f = Number(fim.value)
        let p = Number(passo.value)
        
        if (i < f) {
            for (let c = i; c <= f; c += p) {
                res.innerHTML += `${c} \u{1F449}` 
            }
        } else if (i > f) {
            for (let c = i; i >= f; c -= p) {
                res.innerHTML = `${c} \u{1F449}` 
            }
        }
        res.innerHTML += `\u{1F3C1}` 
    }
}