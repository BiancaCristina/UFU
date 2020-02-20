package VISUAL.VISUAL_ADMIN;

import VISUAL.formAdminUser;
import VISUAL.SUB_VISUAL.formCinemaDelete;
import VISUAL.SUB_VISUAL.formCinemaInsert;

public class formCinema extends javax.swing.JFrame {
    String user;
    String password;
    
    public formCinema(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        cogumelo1.setVisible(false);
        cogumelo2.setVisible(false);
        cogumelo4.setVisible(false);
        
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        cinemaDelete = new javax.swing.JButton();
        cinemaInsert = new javax.swing.JButton();
        cinemaMenuAnterior = new javax.swing.JButton();
        cogumelo1 = new javax.swing.JLabel();
        cogumelo2 = new javax.swing.JLabel();
        cogumelo4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        cinemaDelete.setText("Remover Cinema");
        cinemaDelete.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                cinemaDeleteMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                cinemaDeleteMouseEntered(evt);
            }
        });
        cinemaDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cinemaDeleteActionPerformed(evt);
            }
        });

        cinemaInsert.setText("Inserir Cinema");
        cinemaInsert.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                cinemaInsertMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                cinemaInsertMouseEntered(evt);
            }
        });
        cinemaInsert.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cinemaInsertActionPerformed(evt);
            }
        });

        cinemaMenuAnterior.setText("Menu Anterior");
        cinemaMenuAnterior.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                cinemaMenuAnteriorMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                cinemaMenuAnteriorMouseEntered(evt);
            }
        });
        cinemaMenuAnterior.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cinemaMenuAnteriorActionPerformed(evt);
            }
        });

        cogumelo1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(76, 76, 76)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(cogumelo1)
                    .addComponent(cogumelo2)
                    .addComponent(cogumelo4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(cinemaDelete, javax.swing.GroupLayout.DEFAULT_SIZE, 154, Short.MAX_VALUE)
                    .addComponent(cinemaInsert, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(cinemaMenuAnterior, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(68, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(cinemaInsert)
                    .addComponent(cogumelo1))
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(cinemaDelete)
                    .addComponent(cogumelo2))
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(cogumelo4)
                    .addComponent(cinemaMenuAnterior))
                .addContainerGap(34, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cinemaInsertActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cinemaInsertActionPerformed

        formCinemaInsert form = new formCinemaInsert(this.user, this.password); 
        form.setVisible(true);
        
    }//GEN-LAST:event_cinemaInsertActionPerformed

    private void cinemaDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cinemaDeleteActionPerformed
        
        formCinemaDelete form = new formCinemaDelete(this.user, this.password);
        form.setVisible(true);
    }//GEN-LAST:event_cinemaDeleteActionPerformed

    private void cinemaMenuAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cinemaMenuAnteriorActionPerformed
        formAdminUser form = new formAdminUser(this.user, this.password);
        
        form.setVisible(true);
        dispose();
    }//GEN-LAST:event_cinemaMenuAnteriorActionPerformed

    private void cinemaInsertMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaInsertMouseEntered
        // TODO add your handling code here:
        cogumelo1.setVisible(true);
    }//GEN-LAST:event_cinemaInsertMouseEntered

    private void cinemaInsertMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaInsertMouseExited
        // TODO add your handling code here:
        cogumelo1.setVisible(false);
    }//GEN-LAST:event_cinemaInsertMouseExited

    private void cinemaDeleteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaDeleteMouseEntered
        // TODO add your handling code here:
        cogumelo2.setVisible(true);
    }//GEN-LAST:event_cinemaDeleteMouseEntered

    private void cinemaDeleteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaDeleteMouseExited
        // TODO add your handling code here:
        cogumelo2.setVisible(false);
    }//GEN-LAST:event_cinemaDeleteMouseExited

    private void cinemaMenuAnteriorMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaMenuAnteriorMouseEntered
        // TODO add your handling code here:
        cogumelo4.setVisible(true);
    }//GEN-LAST:event_cinemaMenuAnteriorMouseEntered

    private void cinemaMenuAnteriorMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cinemaMenuAnteriorMouseExited
        // TODO add your handling code here:
        cogumelo4.setVisible(false);
    }//GEN-LAST:event_cinemaMenuAnteriorMouseExited

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formCinema().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton cinemaDelete;
    private javax.swing.JButton cinemaInsert;
    private javax.swing.JButton cinemaMenuAnterior;
    private javax.swing.JLabel cogumelo1;
    private javax.swing.JLabel cogumelo2;
    private javax.swing.JLabel cogumelo4;
    // End of variables declaration//GEN-END:variables
}
