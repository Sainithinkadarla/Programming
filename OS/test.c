



    while(1)
    {
        int min_at=9999;
        int selected = -1;
        for(i=0; i<n; i++)
        {
            if(processes[i].rt>0 && processes[i].at < min_at)
            {
                min_at = processes[i].at;
                selected = i;
            }
        }
        if(selected == -1){break;}
        printf("P%d | ",selected+1);

        time++;
        processes[selected].rt--;

        if(processes[selected].rt==0)
        {
            int wt = time - processes[selected].bt;
            int tat = wt  + processes[selected].bt;

            avg_wt += wt;
            avg_tt += tat;
        }
    } 

    avg_wt/=n;
    avg_tt/=n;

    printf("%f\n%f",avg_wt,avg_tt);
    return 0;
}




}
