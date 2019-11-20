#include "place_extract.h"
#include "ui_place_extract.h"



place_extract::place_extract(int h,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::place_extract)
{//open favorite, set colour, title and icon
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Výpis Oblasti");
    setWindowIcon(QIcon(":/img/mainIcon"));

    //load information from mainwindow
    hh = h;
    QString H = QString::number(hh);
    // select information from database and display it
    QString dotazA = "SELECT oblast, vyska_od, vyska_do, klim_pas,zeme.zeme,rocni_produkce FROM oblasti JOIN zeme ON zeme.zeme_id = oblasti.zeme_id WHERE oblast_id = %1";
    QSqlQuery dotaz (dotazA.arg(H));

     QString oblast;
     QString od;
     QString dov;
     QString klim;
     QString zeme;
     QString produkce;
     while (dotaz.next())
     {
    oblast = dotaz.value("oblast").toString();
    od = dotaz.value("vyska_od").toString();
    dov = dotaz.value("vyska_do").toString();
    klim = dotaz.value("klim_pas").toString();
    zeme = dotaz.value("zeme.zeme").toString();
    produkce = dotaz.value("rocni_produkce").toString();
}
    ui->lineEdit_place->setText(oblast);
    ui->lineEdit_od->setText(od);
    ui->lineEdit_do->setText(dov);
    ui->lineEdit_clima->setText(klim);
    ui->lineEdit_country->setText(zeme);
    ui->lineEdit_production->setText(produkce);


    // display map
    if(zeme == "Bolívie"){

    QPixmap image(":/img/bolivie");
    ui->label_map->setPixmap(image);

       }
    else if(zeme == "Brazílie"){

    QPixmap image(":/img/brazilie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Burundi"){

    QPixmap image(":/img/burundi");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Demokratická republika Kongo"){

    QPixmap image(":/img/kongo");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Dominikánská republika"){

    QPixmap image(":/img/dom");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Ekvádor"){

    QPixmap image(":/img/ekvador");
    ui->label_map->setPixmap(image);

       }
    else if(zeme == "Salvador"){

    QPixmap image(":/img/salvador");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Etiopie"){

    QPixmap image(":/img/etiopie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Guatemala"){

    QPixmap image(":/img/guatemala");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Honduras"){

    QPixmap image(":/img/honduras");
    ui->label_map->setPixmap(image);

    }

    else if(zeme == "Indie"){

    QPixmap image(":/img/indie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Indonésie"){

    QPixmap image(":/img/indonesie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Jemen"){

    QPixmap image(":/img/jemen");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Kamerun"){

    QPixmap image(":/img/kamerun");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Keňa"){

    QPixmap image(":/img/kena");
    ui->label_map->setPixmap(image);

       }
    else if(zeme == "Kolumbie"){

    QPixmap image(":/img/kolumbie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Kostarika"){

    QPixmap image(":/img/kostarika");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Kuba"){

    QPixmap image(":/img/kuba");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Malawi"){

    QPixmap image(":/img/malawi");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Mexiko"){

    QPixmap image(":/img/mexico");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Nepál"){

    QPixmap image(":/img/nepal");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Nicaragua"){

    QPixmap image(":/img/nicaragua");
    ui->label_map->setPixmap(image);

       }
    else if(zeme == "Panama"){

    QPixmap image(":/img/panama");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Papau Nová Guinea"){

    QPixmap image(":/img/guinea");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Peru"){

    QPixmap image(":/img/peru");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Portoriko"){

    QPixmap image(":/img/portoriko");
    ui->label_map->setPixmap(image);

    }

    else if(zeme == "Rwanda"){

    QPixmap image(":/img/rwanda");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Zimbabwe"){

    QPixmap image(":/img/zimbabwe");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == "Uganda"){

    QPixmap image(":/img/uganda");
    ui->label_map->setPixmap(image);

    }
    else if(zeme== "Zambie"){

    QPixmap image(":/img/zambie");
    ui->label_map->setPixmap(image);

    }

    else if(zeme== "Tanzanie"){

    QPixmap image(":/img/tanzanie");
    ui->label_map->setPixmap(image);

    }
    else if(zeme == '-' or zeme == NULL){

    QPixmap image(":/img/ram");
    ui->label_map->setPixmap(image);


}


}

place_extract::~place_extract()
{
    delete ui;
}

// button close
void place_extract::on_close_clicked()
    {
        this->close();
    }
