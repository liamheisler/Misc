import java.util.ArrayList;

/**
 * Manage the stock in a business.
 * The stock is described by zero or more Products.
 * 
 * @author (Robert McGuigan, 20171620, Period 4) 
 * @version (Thursday June 2, 2016 (4 days))
 */
public class StockManager
{
  private ArrayList<Product> stock;       // A list of the products.
  
  /**
   * Initialise the stock manager.
   */
  public StockManager()
  {
    stock = new ArrayList<Product>();
  }

  /**
   * Add a product to the list.
   * @param item The item to be added.
   */
  public void addProduct(Product item)
  {
    stock.add(item);
  }

  /**
   * Receive a delivery of a particular product.
   * Increase the quantity of the product by the given amount.
   * @param id The ID of the product.
   * @param amount The amount to increase the quantity by.
   */
  public void delivery(int id, int amount)
  {
    for (Product item : stock)
    {
      if (id == item.getID())
      {
        item.increaseQuantity(amount);
      }
    }
  }

  /**
   * Try to find a product in the stock with the given id.
   * @return The identified product, or null if there is none
   *         with a matching ID.
   */
  public Product findProduct(int id)
  {
    for (Product item : stock)
    {
      if (id == item.getID())
      {
        return item;
      }
    }
    return null;
  }
  
  /**
   * Locate a product with the given ID, and return how
   * many of this item are in stock. If the ID does not
   * match any product, return zero.
   * @param id The ID of the product.
   * @return The quantity of the given product in stock.
   */
  public int numberInStock(int id)
  {
   for (Product item : stock)
   {
      if (id == item.getID())
      {
        return item.getQuantity();
      }
      else
      {
        System.out.println("Error! Index does not exist!");
      }
   }
   return 0;
  }

  /**
   * Print details of all the products.
   */
  public void printProductDetails()
  {
    if (stock.size() == 0)
    {
      System.out.println("There are no products available.");
    }
    else
    {
      for (Product product : stock)
      {
        System.out.println("ID: " + product.getID());
        System.out.println("Name: " + product.getName());
        System.out.println("Quantity: " + product.getQuantity());
      }
    }
  }

  /**
   * Prints details of all products with stock levels below a given value.
   *
   * @param  level The stock level 
   * @return products with stocks below level
   */
  public void stockLevel(int level)
  {
    if (stock.size() == 0)
    {
      System.out.println("No products to show.");
    }
    else
    {
      for (Product item : stock)
      if(item.getQuantity() < level)
      {
        System.out.println("ID: " + item.getID());
        System.out.println("Name: " + item.getName());
        System.out.println("Quantity: " + item.getQuantity());
      }
   }
  }
}

