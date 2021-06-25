            /* ORDENAR CON DOBLE PUNTERO */

void ordenar_alfabeticamente(t_texto** arreglo){ //   { { e1 , e2  , e3  },{ e1 , e2  , e3  } }
    t_texto arr_aux;
    int i = 0;
    int j = 0;
    
    for( i = 0 ; (*(*(arreglo)+i)).txt != NULL ; i++ ){      // accedo al i elemento del primer arreglo

        for( j = i ; (*(*(arreglo)+j)).txt != NULL ; j++){

            if(strcmp((*(*(arreglo)+i)).txt,(*(*(arreglo)+j)).txt)){

                arr_aux = (*(*(arreglo)+i));
                (*(*(arreglo)+i)) = (*(*(arreglo)+j));
                (*(*(arreglo)+j)) = arr_aux;
            }
        }
    } 
}


            /* ORDENAR CON UN SOLO PUNTERO */

void ordenar_alfabeticamente(t_texto* arreglo){ //   { e1 , e2  , e3  }
    t_texto arr_aux;
    int i = 0;
    int j = 0;  
    
    for( i = 0 ; (*(arreglo+i)).txt != NULL ; i++ ){

        for( j = i ; (*(arreglo + j)).txt != NULL ; j++){

            if(strcmp( (*(arreglo + i)).txt, (*(arreglo + j)).txt )){

                arr_aux = *(arreglo + i);
                *(arreglo + i) = *(arreglo + j);
                *(arreglo + j) = arr_aux;
            }
        }
    } 
}