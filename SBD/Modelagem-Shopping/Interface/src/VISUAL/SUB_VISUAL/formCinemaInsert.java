package VISUAL.SUB_VISUAL;

import TABELAS.Cinema;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class formCinemaInsert extends javax.swing.JFrame {
    String user;
    String password;
    
    public formCinemaInsert(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        nomeCinema = new javax.swing.JTextField();
        adasdas = new javax.swing.JLabel();
        comodoCinema = new javax.swing.JTextField();
        adasdas1 = new javax.swing.JLabel();
        faturamentoCinema = new javax.swing.JTextField();
        insereCinema = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Nome do Cinema:");

        adasdas.setText("Faturamento:");

        adasdas1.setText("Tipo de Cômodo: ");

        insereCinema.setText("Inserir");
        insereCinema.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                insereCinemaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(32, 32, 32)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(adasdas))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(18, 18, 18)
                                .addComponent(nomeCinema, javax.swing.GroupLayout.PREFERRED_SIZE, 201, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(16, 16, 16)
                                .addComponent(faturamentoCinema, javax.swing.GroupLayout.PREFERRED_SIZE, 201, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(adasdas1)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(insereCinema, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(comodoCinema, javax.swing.GroupLayout.DEFAULT_SIZE, 201, Short.MAX_VALUE))))
                .addContainerGap(35, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(39, 39, 39)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(nomeCinema, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(adasdas)
                    .addComponent(faturamentoCinema, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(comodoCinema, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(adasdas1))
                .addGap(18, 18, 18)
                .addComponent(insereCinema)
                .addContainerGap(34, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void insereCinemaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_insereCinemaActionPerformed
        try {
            Cinema cinema = new Cinema(user, password);
            
            float faturamento = Float.parseFloat(faturamentoCinema.getText());
            int tipo_comodo = Integer.parseInt(comodoCinema.getText());
            
            if (!nomeCinema.getText().isEmpty()) {
                cinema.Insert(nomeCinema.getText(), faturamento, tipo_comodo);
            }
            
            else {
                JOptionPane.showMessageDialog(null, "Preenchimento inválido!");
            }
            
            
            dispose(); 
        } 
        
        catch (ClassNotFoundException ex) {
            Logger.getLogger(formCinemaInsert.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }//GEN-LAST:event_insereCinemaActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formCinemaInsert().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel adasdas;
    private javax.swing.JLabel adasdas1;
    private javax.swing.JTextField comodoCinema;
    private javax.swing.JTextField faturamentoCinema;
    private javax.swing.JButton insereCinema;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField nomeCinema;
    // End of variables declaration//GEN-END:variables
}
