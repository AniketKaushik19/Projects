console.log("welcome to wing");
let songindex=0;
let audioElement =new Audio("song/1.mp3");
let mplay=document.getElementById("mplay");
let progressbar=document.getElementById("progressbar");
let songitem=Array.from
(document.getElementsByClassName("songitem"))
let mlab=document.getElementById("mlab");

gif.style.opacity=0
let songs=[
    {songName:"Asei lagi lagan" , filepath:"song/1.mp3" ,coverpath:"cover/1.gif"},

    {songName:"Bhole" , filepath:"song/2.mp3" ,coverpath:"cover/2.jpeg"},

    {songName:"Hanuman" , filepath:"song/3.mp3" ,coverpath:"cover/3.jpeg"},

    {songName:"apne rang me rangle ho" , filepath:"song/4.mp3" ,coverpath:"cover/4.jpeg"},
    {songName:"baba haath" , filepath:"song/5.mp3" ,coverpath:"cover/5.jpeg"},
    {songName:"balaji ke darbar" , filepath:"song/6.mp3" ,coverpath:"cover/6.jpeg"},
    {songName:"hanuman taumahara kya" , filepath:"song/7.mp3" ,coverpath:"cover/7.jpeg"},
    {songName:"shiv" , filepath:"song/8.mp3" ,coverpath:"cover/8.jpeg"},
    {songName:"angan me khel veer hanuman" , filepath:"song/9.mp3" ,coverpath:"cover/9.jpeg"},
    {songName:"balaji mune nokar lale" , filepath:"song/10.mp3" ,coverpath:"cover/10.jpeg"},
]
songitem.forEach((element,i) => {
    element.getElementsByTagName("img")[0].src=songs[i].coverpath;
    element.getElementsByClassName("songname")[0].innerText=songs[i].songName;
});
mplay.addEventListener("click" ,()=>{
    if(audioElement.paused||audioElement.currentTime<=0)
    { audioElement.play()
      mplay.classList.remove("fa-circle-play")
      mplay.classList.add("fa-circle-pause")
      gif.style.opacity=1;
      mlab.innerText=songs[songindex].songName;
    }
  else{
      audioElement.pause()
      makeallplace();
      mplay.classList.add("fa-circle-play")
      mplay.classList.remove("fa-circle-pause")
      gif.style.opacity=0;
    } 
})
//listen to play
audioElement.addEventListener("timeupdate",()=>{
    progress=parseInt((audioElement.currentTime/audioElement.duration)*100);
    progressbar.value=progress
})
progressbar.addEventListener("change",()=>{
   audioElement.currentTime=parseInt(progressbar.value*audioElement.duration/100);
})
const makeallplace=()=>{
    Array.from(document.getElementsByClassName("songitemplay")).forEach((element)=>{
        element.classList.add("fa-circle-play");
        element.classList.remove("fa-circle-pause")
    }) 
}
Array.from(document.getElementsByClassName("songitemplay")).forEach((element)=>{
    element.addEventListener("click",(e)=>{
        makeallplace();
        if(audioElement.paused||audioElement.currentTime<=0)
        {  
            songindex=parseInt(e.target.id)
            audioElement.src=`song/${songindex}.mp3`
            audioElement.currentTime=0
            audioElement.play()
            e.target.classList.remove("fa-circle-play")
            e.target.classList.add("fa-circle-pause")
            mplay.classList.add("fa-circle-pause")
            mplay.classList.remove("fa-circle-play")

            gif.style.opacity=1;
            mlab.innerText=songs[songindex-1].songName;
        }

        else{ 
            audioElement.pause()
            console.log("song item is play class added")
            e.target.classList.remove("fa-circle-pause")
            e.target.classList.add("fa-circle-play")
            mplay.classList.add("fa-circle-play")
            mplay.classList.remove("fa-circle-pause")
            gif.style.opacity=0;

            }  
        })
})
document.getElementById("forward").addEventListener("click",()=>{
    if(songindex>=songitem.length-1){
       songindex=0;
    }
    else{   
        songindex+=1;
    } 
    audioElement.src=`song/${songindex+1}.mp3`;
    audioElement.currentTime=0;
    audioElement.play();
    mplay.classList.add("fa-circle-pause");
    gif.style.opacity=1;
    mlab.innerText=songs[songindex].songName;
})
document.getElementById("backward").addEventListener("click",()=>{
    if(songindex<=1){
        songindex=songitem.length;
    }
    else{
        songindex-=1;
    } 
    mlab.innerText=songs[songindex-1].songName;
    audioElement.src=`song/${songindex}.mp3`;
    audioElement.currentTime=0;
    mplay.classList.add("fa-circle-pause");
    audioElement.play();
    gif.style.opacity=1;
})
