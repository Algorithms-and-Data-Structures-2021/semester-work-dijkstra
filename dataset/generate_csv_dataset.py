import csv
import os
from random import randint


class CreateData:
    @staticmethod
    def create_data():
        os.chdir(os.path.abspath(os.curdir).replace("cmake-build-debug", ""))
        os.chdir(os.path.abspath(os.curdir).replace("benchmark", ""))
        os.chdir(os.path.abspath(os.curdir).replace("dataset", ""))

        try:
            os.mkdir("dataset")
        except Exception as e:
            pass
        os.chdir("dataset")

        try:
            os.mkdir("data")
        except Exception as e:
            pass
        os.chdir("data")

        folders1 = ['insert']
        folders2 = ['01', '02', '03', '04', '05']
        amount = [100, 500, 1000, 5000, 10000]
        for a in folders1:

            try:
                os.mkdir(a)
            except Exception:
                pass
            os.chdir(a)

            for b in folders2:
                try:
                    os.mkdir(b)
                except Exception:
                    continue
                os.chdir(b)

                for i in amount:
                    file_name = str(i) + "x" + str(i) + " adjacency matrix" + ".csv"
                    with open(file_name, "w") as file:
                        dataset = csv.writer(file)
                        n = 0
                        for j in range(i):
                            row = []
                            flag = True
                            for k in range(i):
                                if k == n and flag:
                                    row.append(0)
                                    flag = False
                                    n += 1
                                else:
                                    row.append(randint(1, 1000))

                            dataset.writerow(row)

                os.chdir('..')
            os.chdir('..')

        print('Done =)')


if __name__ == "__main__":
    CreateData.create_data()
