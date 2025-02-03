#include <bits/stdc++.h>
using namespace std;
 
vector<int> countSort(vector<int>& inputArray)
{
 
    int N = inputArray.size();
 
    // Finding the maximum element of array inputArray[].
    int M = 0;
 
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
 
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);
 
    // Mapping each element of inputArray[] as an index
    // of countArray[] array
 
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
 
    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);
 
    for (int i = N - 1; i >= 0; i--)
 
    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
 
        countArray[inputArray[i]]--;
    }
 
    return outputArray;
}
 
// Driver code
int main()
 
{
 
    // Input array
    vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };
 
    // Output array
    vector<int> outputArray = countSort(inputArray);
 
    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";
 
    return 0;
}

"Hey Aeromodelling Club members! 🛩 Exciting news! 🎉🎉🎉🎉
 We're hosting an ----RC Plane Workshop----at NIT Kurukshetra.So get ready to dive into the world of remote-controlled flight! 🚁🔧 Whether you're a seasoned pilot or a newbie, this workshop promises hands-on experience, tips, and the thrill of building and flying RC planes together from scratch ,we will teach you all the  if's and why of aerodynamics from basic to advanced. 🌐✈
        📅 Date: 19th-20th Nov 2023
        🕒 Time: [Insert Time]
        📍 Venue: ED HALL

Don't miss out on this fantastic opportunity to enhance your skills and bond with fellow aviation enthusiasts. Spread the word and let's make this workshop soar!

    See you there! 🚀✨ #RCPlaneWorkshop #NITKurukshetraAero"



    "Hey there👋,Aeromodelling Club stars! 🚀🚀🚀
 Congrats🤝 on making it to the club at NIT Kurukshetra! 🎉 Get ready to soar to new heights and have a blast exploring the world of aerodynamics. 🛩✨ Welcome aboard!

We're thrilled to have you join our tight-knit community of aviation enthusiasts. Whether you're a seasoned pro or just starting to spread your wings, you're in for an exciting journey.Be prepared for a mix of fun, learning, and maybe a few surprises along the way! 🤓🔧

Feel free to reach out if you have any questions or ideas you're itching to explore. Together, let's make this year's aeromodelling experience at NIT Kurukshetra unforgettable!

Safe flights and see you soon and show some excitement by reacting hearts to the message ❤!! 🛫✈ #AeroAdventures #NITKurukshetra"