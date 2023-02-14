#Safe Distance

COVID-2019 has been recognized as a global threat, and several studies are being conducted in order to contribute to the fight and prevention of this pandemic. Currently, there are so many dashboards and statistics around the Coronavirus spread available all over the internet. With so much information and expert opinions, to see different nations adopting different strategies, from complete lockdown to social distancing to herd immunity, there is an immediate need to figure out which strategy is actually effective in nabbing the spread of the deadly virus.
As each and every sector of the market is growing, data is building up day by day, we need
to keep the record of the data which can be helpful for the analytics and evaluation.
Therefore in this report we will be dealing with large data sets with the high-level programming language ’Python’. There are a lot of official and unofficial data sources on the web providing COVID-19 related data. The main goal of this project is to aggregate and analyse the data collected from the one provided by the John Hopkins University’s Center for Systems Science and Engineering (JHU CSSE).
The data is split across the following files: 
1.time_series_19-covid-confirmed_global.csv
2.time_series_19-covid-deaths_global.csv
3.time_series_19-covid-recovered_global.csv
4.https://covid19.who.int/WHO-COVID-19-global-table-data.csv
The dataset that we are using is a Live Dataset, i.e., it is updated on a regular basis and the main advantage of using such a dataset is that whenever we are on this analysis, our data will be up to date and the statistics we see will be current.
Data Visualisation is done on the following:
1.Total Corona Virus Confirmed Cases (Globally)
2.Corona Virus status [Confirmed, Active, Deaths, Recoveries (dynamic chart)]
3.Corona Virus status for individual countries with a search option
We will also make use of a User Defined Function “draw_plot” which is to embed multiple scatter plots in a single graph. It will be done by passing each plot and its configurations as arguments.


A real time CSV file is read and then converted into a Pandas dataframe and NumPy is used for data handling of the dataset (keeping only the necessary fields and dropping the unwanted). It is the Cumulative dataset from the original file.
A global record (summary) will be created by summing various aspects of any individual country. This will be then used to graph the scatter plot – Global Graph and the Increase in COVID cases with time graph.
Draw_plot function will be used to form a multiple scatter plot to embed the aggregate records of – Confirmed, Active, Deaths and Recoveries. This function will return a template (a summary of cases until now) of the graph with multiple plots. This function can be extended by passing various parameters.
The country wise cumulative data is cleaned by removing the unnecessary field i.e., getting the fields of individual countries ready. An input country name is given by the user which is then checked for its availability in the dataset and then that country’s individual graph is displayed.
