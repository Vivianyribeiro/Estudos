function  verifica() {   
    var data = new Date()
    var ano = data.getFullYear()
    var fano = document.getElementById('textano')
    var res = document.querySelector('div#res')
    if (fano.value.length == 0 || Number(fano.value) > ano){
        window.alert('[ERRO] Verifique os dados e tente novamente.')
    } else {
        var fsex = document.getElementsByName('radsex')
        var idade = ano - Number(fano.value)
        var genero = ''
        var img = document.createElement('img')
        img.setAttribute('id', 'img')
        if (fsex[0].checked) {
            genero = 'Homem'
            if(idade >= 0 && idade < 10) {
                //crianca
                img.setAttribute('src', '../imagens/crianca-homem.png')
            } else if (idade < 21) {
                //jovem
                img.setAttribute('src', '../imagens/homem-adolescente.png')
            } else if (idade < 50){
                //adulto
                img.setAttribute('src', '../imagens/homem-adulto.png')
            } else {
                //idoso
                img.setAttribute('src', '../imagens/homem-idoso.png')
            }
        } else if (fsex[1].checked) {
            genero = 'Mulher'
            if(idade >= 0 && idade <10) {
                //crianca
                img.setAttribute('src', '../imagens/mulher-crianca.png')
            } else if (idade < 21) {
                //jovem
                img.setAttribute('src', '../imagens/mulher-adolescente.png')
            } else if (idade < 50){
                //adulto
                img.setAttribute('src', '../imagens/mulher-adulta.png')
            } else {
                //idoso
                img.setAttribute('src', '../imagens/mulher-idosa.png')
            }
        }
        res.style.textAlign = 'center'
        res.innerHTML = `Detectamos ${genero} com ${idade} ano/s.`
        res.appendChild (img)
    }
}    