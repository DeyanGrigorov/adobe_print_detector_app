# This application detects if print button is clicked and if it was, a warning pop up message appears.
More specifically the app contains a dll developed on c++ and a python script which calls the dll and making it listen in the background constantly.
The dll listens for a (className, L"Button") and (windowText, L"Print") and if it detects click on this button a warning pop up message appears(the message can be changed from the source.cpp file, form the dll code)
The code is then bundled together with py2exe into application, you can find the exe in the dist folder.
In the repo, there is also a installer made with inno setup compiler which is located in the output folder, this way the app can be easily distributed to other machines, off course you can also just copy the exe file from the dist folder and use it too.


More info:

The application is tested on windows 10 machines and it is mainly developed and tested to work with adobe reader, however if another print button is clicked with the 'className Button' and text 'Print' it will also behave the same.

When you open a pdf file with adobe reader and click on the print button, the pop up message will appear:


![image](https://user-images.githubusercontent.com/71971762/215797500-7275e3de-37cb-476c-9176-5335b083c0d2.png)
![image](https://user-images.githubusercontent.com/71971762/215797602-2411a95e-70d6-4d1e-957c-4f730383e20a.png)
![image](https://user-images.githubusercontent.com/71971762/215797747-8223fba7-63f2-45c2-a46a-25ed62633425.png)

Please note that if you want the message to have different content you will need to change it from the source.cpp file from the vs_repo and then build the solution again.
After that you will have to paste the new dll into the directory where the python script is located and bundle it together with some library like py2exe, or just contact me and I will gladly assist.


