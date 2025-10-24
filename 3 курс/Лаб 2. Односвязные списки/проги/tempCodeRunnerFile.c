for(int i = sizeof(test)/sizeof(test[0]) - 1; i >= 0; i--) {
        push(&list, test[i]);
        printList(list);
    }