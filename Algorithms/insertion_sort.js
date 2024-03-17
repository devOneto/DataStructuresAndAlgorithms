function insertion_sort(array){
    let i = 1;
    while( i < array.length ){
        let j = i;
        while(j > 0 && array[j-1] > array[j] ){
            let aux = array[j-1];
            array[j-1] = array[j];
            array[j] = aux;
            j = j-1;
        }
        i++;
    }
    return array;
}

console.log(insertion_sort([6,2,7,5,3,1,4]));