function  carregar() {   
    var msg = window.document.getElementById('msg')
    var img = window.document.getElementById('imagem')
    var data = new Date()
    var hora = 18
    msg.innerHTML = `Agora são ${hora} horas.`
    if (hora >= 0 && hora < 12 ){
        //Bom dia
        img.src = '../imagens/manhazinha.png'
        document.body.style.background = '#dab184'
    } else if (hora >= 12 && hora < 18) {
        //Boa Tarde!!
        img.src = '../imagens/tarde.png'
        document.body.style.background = '#a86f4a'
    } else {
        //Boa Noite!
        img.src = '../imagens/noite.png'
        document.body.style.background = '#ad5568'
    }
}    