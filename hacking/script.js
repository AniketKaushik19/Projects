const messages=[
    "Instilizing hacking...",
    "Connecing to server....",
    "Connected to the server....",
    "User name Aniket Kaushik...",
    "Connecting to Insta...",
    "Connecting to Facebook...",
    "Connecting to Snapchat...",
    "Connecting to Bank account ...",
    "Connected Successful ..."
  ]
  async function sleep(second) {
      return new Promise((resolve, reject) => {
          setTimeout(() => { resolve(true) }, second * 1000)
      })
  }
  const showhack=async(messages)=>{
    await sleep(2)
    text.innerHTML=text.innerHTML+messages+"<br>"}
  
  (async()=>{
    for(let i=0;i<messages.lenght;i++){
      await showhack(messages[i])
    }
  })()