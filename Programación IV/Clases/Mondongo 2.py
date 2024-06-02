class Calculo:
    def __init__(self, *args):
        if len(args) > 3:
            print("El objeto tiene mas de 3 elementos")
        else:
            print("El objeto NO tiene mas de 3 elementos")

calculo = Calculo(1, 2, 3, 4, 5, 6, 7, 9)