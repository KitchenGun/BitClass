package woosongbit.sample3;

abstract class Player
{
	int currentPos;
	Player()
	{
		currentPos=0;
	}
	
	abstract void stop();
	abstract void play(int pos);

	void Play()
	{
		play(currentPos);
		stop();
	}
}

class AudioPlayer extends Player
{
	AudioPlayer()
	{
		super();
	}
	@Override
	void stop() {
		// TODO Auto-generated method stub
		System.out.println("AudioPlayer.stop()");
		
	}

	@Override
	void play(int pos) {
	
		// TODO Auto-generated method stub
		System.out.println("AudioPlayer.play()");
	}
}

public class Start
{
	public static void main(String[] args) 
	{
		Player p = new AudioPlayer();
		p.Play();
	}
}
