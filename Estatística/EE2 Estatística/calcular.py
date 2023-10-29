import statistics

class Decimal:
        def __init__(self, dec):
            self.dec = dec
            self.lista_atom = []
        def adicionar(self, atomo):
            self.lista_atom.append(atomo)
        def getInterval(self):
            print(f'Na faixa de {self.dec}0, anos há {len(self.lista_atom)} pessoas')


def DistributionFrequery(lista):
    lista_dec = []
    lista_dec_int = []
    for i in lista:
        if i // 10 not in lista_dec_int:
            lista_dec_int.append(i//10)
            lista_dec.append(Decimal(i//10))
        for j in lista_dec:
            if i // 10  == j.dec:
                j.adicionar(i)
    lista_dec = sorted(lista_dec, key=lambda x: x.dec)
    for i in lista_dec:
        i.getInterval()
        
MelhoresAtrizes = [
22 ,37, 28 ,63 ,32, 26, 31, 27, 27 ,28,
30 ,26, 29 ,24 ,38, 25, 29, 41, 30 ,35,
35 ,33, 29 ,38 ,54, 24, 25, 46, 41 ,28,
40 ,39, 29 ,27 ,31, 38, 29, 25, 35 ,60,
43 ,35, 34 ,34 ,27, 37, 42, 41, 36 ,32,
41 ,33, 31 ,74 ,33, 50, 38, 61, 21 ,41,
26 ,80, 42 ,29 ,33, 35, 45, 49, 39 ,34,
26 ,25, 33 ,35 ,35, 28, 30, 29, 61]

MelhoresAtores = [
44 ,41 ,62 ,52, 41 ,34 ,34 ,52 ,41 ,37,
38 ,34 ,32 ,40, 43 ,56 ,41 ,39 ,49 ,57,
41 ,38 ,42 ,52, 51 ,35 ,30 ,39 ,41 ,44,
49 ,35 ,47 ,31, 47 ,37 ,57 ,42 ,45 ,42,
44 ,62 ,43 ,42, 48 ,49 ,56 ,38 ,60 ,30,
40 ,42 ,36 ,76, 39 ,53 ,45 ,36 ,62 ,43,
51 ,32 ,42 ,54, 52 ,37 ,38 ,32 ,45 ,60,
46 ,40 ,36 ,47, 29 ,43 ,37 ,38 ,45]

#Melhores Atores
print('Dados dos Melhores Atores')
print(f'A média de Melhores Atores é {sum(MelhoresAtores)/len(MelhoresAtores)}')
print(f'O Desvio Padrão é: {statistics.pstdev(MelhoresAtores)}')
print(f'A moda é {statistics.mode(MelhoresAtores)}')
print(f'A mediana é {statistics.median(MelhoresAtores)}')
print(f'O mais novo a vencer o prêmio teve {min(MelhoresAtores)} anos ao vencer')
print('Distribuição de Frequência dos Atores:')
DistributionFrequery(MelhoresAtores)

#Melhores Atrizes
print('\nDados dos Melhores Atrizes')
print(f'A média de Melhores Atrizes é {sum(MelhoresAtrizes)/len(MelhoresAtrizes)}')
print(f'O Desvio Padrão é: {statistics.pstdev(MelhoresAtrizes)}')
print(f'A moda é {statistics.mode(MelhoresAtrizes)}')
print(f'A mediana é {statistics.median(MelhoresAtrizes)}')
print(f'A mais nova a vencer o prêmio teve {min(MelhoresAtrizes)} anos ao vencer')
print('Distribuição de Frequência das Atrizes:')
DistributionFrequery(MelhoresAtrizes)
