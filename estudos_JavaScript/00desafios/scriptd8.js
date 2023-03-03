function calcula() {
    let preco = parseFloat(document.getElementById('preço').value)
    let i = parseFloat(document.querySelector('input#tx').value)
    let res = document.querySelector('article#res')
    let calculo_desconto = preco - (preco * i /100)
    res.innerHTML = `Preço com desconto: R$ ${calculo_desconto.toFixed(2)}`
}
