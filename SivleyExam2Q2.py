#line problem
#exam 2 question 2
#Codey Sivley
#OOP Fall 2021
import csv
from csv import reader

def readAnimalRange(csvFile):
    formattedData = []

    with open(csvFile, newline='') as animalData:
        rawData = csv.reader(animalData)
        for i in list(rawData):
            formattedData = formattedData + [tuple(i)]

    return formattedData


print(readAnimalRange('e2p2data.csv'))
