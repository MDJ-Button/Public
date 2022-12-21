import os
import requests
import csv
import pandas as pd
import numpy as np
import urllib.request
from bs4 import BeautifulSoup
from forex_python.converter import CurrencyRates

def ScrapeEbayTitlesAndPrices(strLogHTML, strConvertCurrency):
    soup = BeautifulSoup(reponse.text, "lxml");
    
    if(strLogHTML == "Yes"):
        print('---What do you want to name the log file: ');
        strLogFileName = input();
        f = open("LogFileName.html", "w");
        f.write(str(soup));
        f.close();
    
    arrTitles = [];
    arrPrices = [];
    arrImages = [];
    
    strFromCurrency = '';
    strToCurrency = '';
    
    if(strConvertCurrency == "Yes"):
        c = CurrencyRates();
        
        print('---Convert from: ');
        strFromCurrency = input();
        
        print('---Convert to: ');
        strToCurrency = input();
    
    for i, details in enumerate(soup.find_all("li", class_=("s-item s-item__pl-on-bottom s-item--watch-at-corner"))):
        title = details.find("h3", class_=("s-item__title")).text;
        price = details.find("span", class_=("s-item__price")).text;
        image = details.find("img", class_=("s-item__image-img"));
        
        if(strConvertCurrency == "Yes"):
            price = price.replace(',', "");
            price = price.replace(strFromCurrency + ' ', "");
            price = float(price);
            price = (c.convert(strFromCurrency, strToCurrency, price));
            
        print("[{}] ".format(i) + title + " " + str(price));
        arrTitles.append(title);
        arrPrices.append(price);
        
        if image.has_attr('data-src'):
            print(image['data-src']);
            arrImages.append(image['data-src']);
        else:
            print(image['src']);
            arrImages.append(image['src']);
     
    print('---What do you want to name the .csv file: ');
    strCSVFile = input();
    x = {"Name" : arrTitles, "Price" : arrPrices, "Images" : arrImages};
    df = pd.DataFrame.from_dict(x, orient='index');
    df = df.transpose();
    df.to_csv(strCSVFile + '.csv', index=False);

bLoopProgram = True;
while bLoopProgram:
    print('Do you want to scrape a page: ');
    strScrapePage = input();
    
    if(strScrapePage == "Yes"):
        print('-What page do you want to scrape: ');
        strUrl = input();
    
        reponse = requests.get(strUrl);
    
        if(reponse.ok):
            print('--Do you want to log the file: ');
            strLogFile = input();
            print('--Do you want to convert the currency: ');
            strConvertCurrency = input();
            
            ScrapeEbayTitlesAndPrices(strLogFile, strConvertCurrency);
        else:
            print('-' + strUrl + ' is not reachable.');
    else:
        print('Closing.');
        bLoopProgram = False;