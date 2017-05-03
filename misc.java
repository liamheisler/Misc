import java.util.ArrayList;
import java.util.Iterator;

/**
 * A simple model of an auction.
 * The auction maintains a list of lots of arbitrary length.
 *
 * @author David J. Barnes and Michael Kölling.
 * @version 2011.07.31
 */
public class Auction
{
  private ArrayList<Lot> lots;  // The list of Lots in this auction.
  private int nextLotNumber;    // The number that will be given to the next lot
                                // entered into this auction.

  /**
   * Create a new auction.
   */
  public Auction()
  {
    lots = new ArrayList<Lot>();
    nextLotNumber = 1;
  }

  /**
   * Enter a new lot into the auction.
   * @param description A description of the lot.
   */
  public void enterLot(String description)
  {
    lots.add(new Lot(nextLotNumber, description));
    nextLotNumber++;
  }

  /**
   * Show the full list of lots in this auction.
   */
  public void showLots()
  {
    for(Lot lot : lots)
    {
      System.out.println(lot.printDetails());
    }
  }
    
  /**
   * Make a bid for a lot.
   * A message is printed indicating whether the bid is
   * successful or not.
   * 
   * @param lotNumber The lot being bid for.
   * @param bidder The person bidding for the lot.
   * @param value  The value of the bid.
   */
  public void makeABid(int lotNumber, Person bidder, long value)
  {
    Lot selectedLot = getLot(lotNumber);
    if(selectedLot != null)
    {
      Bid bid = new Bid(bidder, value);
      boolean successful = selectedLot.bidFor(bid);
      if(successful)
      {
        System.out.println("The bid for lot number " + lotNumber + " was successful.");
      }
      else
      {
        // Report which bid is higher.
        Bid highestBid = selectedLot.getHighestBid();
        System.out.println("Lot number: " + lotNumber +
                           " already has a bid of: " +
                           highestBid.getValue());
      }
    }
  }

  /**
   * Return the lot with the given number. Return null
   * if a lot with this number does not exist.
   * @param lotNumber The number of the lot to return.
   */
  public Lot getLot(int lotNumber)
  {
    if((lotNumber >= 1) && (lotNumber < nextLotNumber))
    {
      Iterator<Lot> it = lots.iterator();
      while(it.hasNext())
      {
        Lot lot = it.next();
        if (lot.getNumber() == lotNumber)
        {
          return lot;
        }
      }
      return null;
    }
    else
    {
      System.out.println("Lot number: " + lotNumber + " does not exist.");
      return null;
    }
  }
  
  /**
   * An example of a method - replace this comment with your own
   *
   * @param  y   a sample parameter for a method
   * @return     the sum of x and y
   */
  public void close() 
  {
    if (lots.size() == 0)
    {
      System.out.println("No lots");
    }
    else
    {
     for (Lot lot : lots)
     {
       System.out.println(lot.getNumber() + ": " + lot.getDescription());
       Bid bid = lot.getHighestBid();
       if (bid != null)
       {
         System.out.println("High bid: $" + lot.getHighestBid().getValue());
         System.out.println("Winner: " + lot.getHighestBid().getBidder().getName());
       }
       else
       {
         System.out.println("Not Sold");
       }
     }
   } 
  }

  /**
   * An example of a method - replace this comment with your own
   *
   * @param  y   a sample parameter for a method
   * @return     the objects that are unsold
   */
  public ArrayList getUnsold()
   {
    ArrayList<Lot> unsold = new ArrayList<Lot>();
    for (Lot lot : lots)
    {
      if(lot.getHighestBid() == null)
      {
        unsold.add(lot);
      }
    }
    return unsold;
  }
  
  /**
   * Remove the lot with the given lot number.
   *
   * @param  number The number of the lot to be removed.
   * @return The lot with the given number, or null if there is no such lot.
   */
  public Lot removeLot(int lotNumber)
  {
    if((lotNumber >= 1) && (lotNumber < nextLotNumber))
    {
      Iterator<Lot> it = lots.iterator();
      while(it.hasNext())
      {
        Lot lot = it.next();
        if (lot.getNumber() == lotNumber)
        {
          it.remove();
          return lot;
        }
      }
      return null;
    }
    else
    {
      System.out.println("Lot number: " + lotNumber + " does not exist.");
      return null;
    }
  }
 }
