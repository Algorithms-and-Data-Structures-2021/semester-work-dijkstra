from random import randint
from os import mkdir

ops = ('firstNode', 'secondNode', 'distance')

setOfNodes = set()
value = 0
value1 = 0
value2 = 0


def node1_generator(min_value: int = 0, max_value: int = 5):
    """Function to generate values for tests"""
    for op in ops:
        if op == "firstNode":
            mkdir(op)
            for elements_quantity in (1, 2, 3, 4):
                with open(f'{op}/data({elements_quantity}).txt', "a") as inp:
                    for i in range(elements_quantity):
                        value1 = randint(min_value, max_value)
                        inp.write(str(value1) + " ")
                    inp.write("\n")


value = value1


def node2_generator(min_value: int = 0, max_value: int = 5):
    """Function to generate values for tests"""
    for op in ops:
        if op == "secondNode":
            mkdir(op)
            for elements_quantity in (1, 2, 3, 4):
                with open(f'{op}/data({elements_quantity}).txt', "a") as inp:
                    for i in range(elements_quantity):
                        if value2 != value:
                            value2 = randint(min_value, max_value)
                        inp.write(str(value1) + " ")
                    inp.write("\n")


def distance_generator(min_value: int = 0, max_value: int = 10):
    """Function to generate values for tests"""
    for op in ops:
        mkdir(op)
        for elements_quantity in (1, 2, 3, 4):
            with open(f'{op}/data({elements_quantity}).txt', "a") as inp:
                for i in range(elements_quantity):
                    distance = randint(min_value, max_value)
                    inp.write(str(distance) + " ")
                inp.write("\n")


if __name__ == '__main__':
    help_message = """"""
    node1_generator()
    node2_generator()
    distance_generator()
    print('successfully')
