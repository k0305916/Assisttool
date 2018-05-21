import sys
import os
import threading
import pandas as pd

def FileProcess(filelist):
    for file in filelist:
        data = pd.read_excel(file,sheetname=None)

print('file path is:',sys.argv[1])
filelist = os.listdir(sys.argv[1])
print('processing now, do not close windows please.')

#create a thread to process files
FileProcessThread = threading.Thread(FileProcess, filelist)
FileProcessThread.start()
FileProcessThread.join()

print('processing over. Check please.')
