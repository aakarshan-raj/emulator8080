use std::{fs::File, error::Error,io::Read, env};


fn main()->Result<(),Box<dyn Error>>{

    let args:Vec<String> = env::args().collect();
    if args.len() < 2 {
         eprintln!("provide file name");
         return Ok(());
    }
    let mut file_handler = File::open(&args[1])?;
   

    let mut instructions:Vec<u8> = Vec::new();

    file_handler.read_to_end(&mut instructions)?;

    for opcode in instructions{
        println!("0x{:x}",opcode);
    }

    Ok(())

}