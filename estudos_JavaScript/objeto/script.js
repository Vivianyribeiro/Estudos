let amigo = {nome: 'Jose', 
sexo: 'M',
peso: 87.5,
engordar(p=0) {
    console.log('Engordou')
    this.peso += p
    }
}

console.log(`${amigo.nome} pesa ${amigo.peso} kg`)